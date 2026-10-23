"""Check measured heading retention, including the ordinary connector between holes."""
import argparse
import json
import math
from pathlib import Path

from two_hole_low_hold_audit import audit as low_audit


def audit(path):
    result = low_audit(path)
    data = json.loads(path.read_text())
    passages = data['plans'][0]['passages']
    first_e = next(e for e in data['events'] if e['uid'] == passages[0]['uid'] and e['type'] == 2)
    final_d = next(e for e in data['events'] if e['uid'] == passages[-1]['uid'] and e['type'] == 5)
    rows = [r for r in data['trace'] if r['progress'] is not None and
            first_e['progress'] <= r['progress'] < final_d['progress'] - .01]
    assert rows and all(r['rotation_mode'] in ('HOLE_ALIGN', 'GIMBAL_HOLD') for r in rows), 'gimbal hold was released; automatic spin resumed'
    # Consecutive samples are frequent enough to unwrap a continuous spin, rather than
    # mistaking one full rotation for the same orientation. Keep contact jitter visible.
    yaw = rows[0]['yaw']
    angles = [yaw]
    for previous, current in zip(rows, rows[1:]):
        yaw += math.remainder(current['yaw'] - previous['yaw'], 2 * math.pi)
        angles.append(yaw)
    excursion = max(angles) - min(angles)
    assert excursion < .15, f'gimbal heading changed by {excursion:.3f}rad after alignment'
    assert any(r['rotation_mode'] == 'NAV_AUTO' for r in data['trace'] if
               r['progress'] is not None and r['progress'] > final_d['progress'] + .03), 'normal spin did not resume after final clearance'
    result.update(maximum_gimbal_heading_excursion_rad=excursion, alignment_continuous=True)
    return result


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('runs', type=Path, nargs='+')
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    result = json.dumps([audit(p) for p in args.runs], indent=2)
    if args.output:
        args.output.write_text(result + '\n')
    print(result)
