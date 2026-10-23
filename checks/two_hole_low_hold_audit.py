"""Verify actual Gazebo LOW continuity across two separated passages."""
import argparse
import json
from pathlib import Path


def audit(path):
    data = json.loads(path.read_text())
    assert data['model'] == 3 and data['result'] == 'PASS' and data['action_success']
    assert not data.get('cleanup_remaining_pids')
    plans = [p for p in data['plans'] if p['status'] == 0]
    assert len(plans) == 1, 'navigation needed replanning'
    passages = plans[0]['passages']
    assert len(passages) == 2
    assert passages[0]['events'][5]['arc'] < passages[1]['events'][0]['arc'], 'requires separated A/D ranges'
    assert all(t['decision'] == 0 and t['state'] != 4 for t in data['transitions'])
    entered = next(e for e in data['events'] if e['uid'] == passages[0]['uid'] and e['type'] == 2)
    departed = next(e for e in data['events'] if e['uid'] == passages[1]['uid'] and e['type'] == 5)
    trace = [r for r in data['trace'] if r['progress'] is not None]
    # Start at actual completion of the first LOW, rather than assuming A means ready.
    prepared = next(r for r in trace if r.get('structure_feedback') and
                    r['structure_feedback']['target'] == 1 and r['structure_feedback']['status'] == 1)
    held = [r for r in trace if r['t'] >= prepared['t'] and r['progress'] < departed['progress'] - .01]
    assert held and all(r['lift'] is not None and r['lift'] < .008 for r in held), 'mechanism rose between passages'
    feedback = [r['structure_feedback'] for r in held if r.get('structure_feedback')]
    assert feedback and all(f['target'] == 1 and f['status'] == 1 for f in feedback)
    assert len({f['request_id'] for f in feedback}) == 1, 'LOW action was restarted'
    assert entered['lift'] < .008
    assert any(r.get('structure_feedback') and r['structure_feedback']['target'] == 2
               for r in trace if r['progress'] >= departed['progress'] - .01), 'final restoration missing'
    return dict(run=path.parent.name, case=data['case'], result='PASS',
                low_request_id=feedback[0]['request_id'], maximum_held_lift=max(r['lift'] for r in held),
                first_D=passages[0]['events'][5]['arc'], second_A=passages[1]['events'][0]['arc'])


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('runs', type=Path, nargs='+')
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    result = json.dumps([audit(p) for p in args.runs], indent=2)
    if args.output:
        args.output.write_text(result + '\n')
    print(result)
