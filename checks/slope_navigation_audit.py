"""Audit captured Gazebo runs: real actions, traversal events and command continuity.

Run after run_case.py; never infer a pass from the absence of console errors.
"""
import argparse
import json
import math
from pathlib import Path

import yaml

ROOT = Path(__file__).resolve().parents[1]


def cross(a, b):
    return a[0] * b[1] - a[1] * b[0]


def inside(point, polygon):
    hit = False
    x, y = point
    for a, b in zip(polygon, polygon[1:] + polygon[:1]):
        if (a[1] > y) != (b[1] > y):
            if x < a[0] + (y - a[1]) * (b[0] - a[0]) / (b[1] - a[1]):
                hit = not hit
    return hit


def slopes(points, regions):
    """Clip the actual accepted route against physical slope polygons."""
    found = []
    for region in regions:
        if region['type'] != 'slope':
            continue
        polygon = region['geometry']['polygon']
        yaw = math.radians(region['attributes']['uphill_yaw_deg'])
        up = math.cos(yaw), math.sin(yaw)
        arc = 0.
        sections = []
        for a, b in zip(points, points[1:]):
            v = b[0] - a[0], b[1] - a[1]
            length = math.hypot(*v)
            if length < 1e-9:
                continue
            cuts = [0., 1.]
            for c, d in zip(polygon, polygon[1:] + polygon[:1]):
                w, delta = (d[0] - c[0], d[1] - c[1]), (c[0] - a[0], c[1] - a[1])
                det = cross(v, w)
                if abs(det) < 1e-12:
                    continue
                t, u = cross(delta, w) / det, cross(delta, v) / det
                if 0 < t < 1 and 0 <= u <= 1:
                    cuts.append(t)
            cuts.sort()
            for lo, hi in zip(cuts, cuts[1:]):
                if not inside((a[0] + v[0] * (lo + hi) / 2, a[1] + v[1] * (lo + hi) / 2), polygon):
                    continue
                begin, end = arc + lo * length, arc + hi * length
                uphill = v[0] * up[0] + v[1] * up[1] > 0
                if sections and abs(sections[-1]['end'] - begin) < 1e-6 and sections[-1]['uphill'] == uphill:
                    sections[-1]['end'] = end
                else:
                    sections.append(dict(id=region['id'], begin=begin, end=end, uphill=uphill))
            arc += length
        found.extend(sections)
    return sorted(found, key=lambda s: s['begin'])


def audit(path):
    data = json.loads(path.read_text())
    assert data['model'] == 3, 'only model 3 is in this acceptance scope'
    assert data['result'] == 'PASS' and data['action_success'], data.get('error')
    assert not data.get('cleanup_remaining_pids'), 'simulation left live processes'
    assert len([p for p in data['plans'] if p['status'] == 0]) == 1, 'replanning/recovery masked a failed traversal'
    stops = [t for t in data['transitions'] if t['decision'] != 0 or t['state'] == 4]
    assert not stops, stops
    plan = data['plans'][0]
    # 本轮实际使用场景：目标越过最后洞口的出口直线，完成后交给普通导航。
    for passage in plan['passages']:
        exit_straight = passage['events'][4]
        assert exit_straight['range'] == 0 and exit_straight['arc'] < plan['length'], 'goal remains inside passage exit straight'
    events = data['events']
    trace = data['trace']
    goal = plan['path'][-1][:2]
    started, stopped_since = False, None
    for row in trace:
        speed = math.hypot(row['command_x'], row['command_y'])
        started |= speed > .03
        if started and speed < .03 and math.dist((row['x'], row['y']), goal) > .15:
            if stopped_since is None:
                stopped_since = row['t']
            assert row['t'] - stopped_since < .8, 'persistent zero command away from goal'
        else:
            stopped_since = None
    passages = []
    for passage in plan['passages']:
        expected = {e['type'] for e in passage['events'] if e['range'] == 0}
        actual = [e['type'] for e in events if e['uid'] == passage['uid']]
        assert expected == set(actual) and len(actual) == len(set(actual)), (expected, actual)
        for event in events:
            if event['uid'] == passage['uid'] and event['type'] == 2:
                assert event['lift'] is not None and event['lift'] < .008
        a, d = passage['events'][0]['arc'], passage['events'][5]['arc']
        samples = [r for r in trace if r['progress'] is not None and max(.1, a) < r['progress'] < min(d, plan['length'] - .15)]
        speeds = [math.hypot(r['command_x'], r['command_y']) for r in samples]
        assert speeds and min(speeds) > .03, 'zero command during the preparation/traversal range'
        passages.append(dict(hole=passage['hole'], uphill=passage['uphill'],
                             minimum_command_speed=min(speeds), events=actual))
    physical = slopes(plan['path'], yaml.safe_load((ROOT / 'map/terrain.yaml').read_text())['regions'])
    for slope in physical:
        samples = [r for r in trace if r['progress'] is not None and slope['begin'] < r['progress'] < slope['end']]
        assert samples, 'slope was not sampled'
        command = [math.hypot(r['command_x'], r['command_y']) for r in samples]
        assert min(command) > .03, 'zero command on slope'
        # Check real Gazebo motion as well as commands: a nonzero command can still stall.
        for first in samples:
            later = next((r for r in samples if r['t'] >= first['t'] + .8), None)
            if later is not None:
                assert math.dist((first['x'], first['y']), (later['x'], later['y'])) > .04, 'physical standstill on slope'
        before = [r for r in trace if r['progress'] is not None and r['progress'] <= slope['begin']]
        assert before and before[-1]['lift'] is not None and before[-1]['lift'] < .008, 'LOW unfinished at physical slope entry'
        arc, heading = 0., None
        for a, b in zip(plan['path'], plan['path'][1:]):
            length = math.dist(a[:2], b[:2])
            if arc + length >= slope['begin'] and length > 1e-9:
                heading = math.atan2(b[1] - a[1], b[0] - a[0])
                break
            arc += length
        ready = [r for r in before if r['progress'] > max(0., slope['begin'] - .3) and
                 r['lift'] is not None and r['lift'] < .008 and r['chassis_yaw'] is not None and
                 abs(math.remainder(r['chassis_yaw'] - heading, math.pi / 2)) <= .05 and
                 r['rotation_rates'] is not None and max(map(abs, r['rotation_rates'])) < .1]
        assert ready, 'no measured LOW/aligned/stopped preparation before physical slope entry'
        measured = [math.hypot(r['vx'], r['vy']) for r in samples]
        slope.update(minimum_command_speed=min(command), maximum_command_speed=max(command),
                     minimum_measured_horizontal_speed=min(measured), maximum_measured_horizontal_speed=max(measured))
    return dict(case=data['case'], run=str(path.parent.name), result='PASS', explicit_stops=0, passages=passages, slopes=physical)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('runs', type=Path, nargs='+')
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    summary = [audit(path) for path in args.runs]
    text = json.dumps(summary, indent=2)
    if args.output:
        args.output.write_text(text + '\n')
    print(text)
