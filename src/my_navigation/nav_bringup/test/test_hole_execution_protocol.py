#!/usr/bin/env python3
"""只检查生成消息的数据契约；不启动ROS节点、不发送运动命令。"""
import unittest
from nav_interfaces.msg import NavigationPlan, HoleEvent, HoleStructureRequest, HoleStructureFeedback


class ProtocolTest(unittest.TestCase):
    def test_identity_and_ranges(self):
        p = NavigationPlan()
        p.session_id, p.goal_id, p.plan_id = 'session', 'goal', 2
        p.status = p.INVALIDATED
        self.assertNotEqual(p.ACTIVE, p.INVALIDATED)
        e = HoleEvent()
        e.range_status = e.BEFORE_PATH
        e.point_valid = False
        self.assertFalse(e.point_valid)
        self.assertNotEqual(e.BEFORE_PATH, e.ON_PATH)

    def test_request_feedback_are_correlatable(self):
        q, f = HoleStructureRequest(), HoleStructureFeedback()
        q.session_id, q.goal_id, q.request_id, q.requirement_revision = 's', 'g', 7, 3
        q.target, q.traversal_uids = q.LOW, ['visit1', 'visit2']
        f.session_id, f.goal_id = q.session_id, q.goal_id
        f.request_id, f.requirement_revision, f.target = q.request_id, q.requirement_revision, q.target
        f.status = f.EXECUTING
        self.assertEqual(f.request_id, q.request_id)
        self.assertNotEqual(f.status, f.COMPLETED)
        self.assertFalse(f.normal_clearance)
        self.assertFalse(f.whole_vehicle_clear)
        self.assertFalse(f.moving_transition_supported)


if __name__ == '__main__':
    unittest.main()
