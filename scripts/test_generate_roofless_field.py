"""Regression checks for the original and already-cleaned field meshes."""

import contextlib
import io
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

import generate_roofless_field as field


class RooflessFieldTests(unittest.TestCase):
    def test_known_sources_produce_the_same_mesh(self):
        outputs = []
        for tree, floating_count in (("navigationsim", 85), ("navigatiosim2", 0)):
            with self.subTest(tree=tree), tempfile.TemporaryDirectory() as directory:
                root = Path(directory)
                source = field.ROOT / tree / "src/sentry_velocity/gazeboworld/models/rmuc_2026"
                target = root / "field"
                with patch.multiple(field, ROOT=root, SOURCE=source, TARGET=target):
                    with contextlib.redirect_stdout(io.StringIO()):
                        field.build()
                outputs.append((target / "meshes/rmuc_2026.stl").read_bytes())
                report = json.loads((root / "test/results/roofless_geometry.json").read_text())
                self.assertEqual(report["removed_floating_mark_triangles"],
                                 {"A1": floating_count, "A2": floating_count})
                self.assertEqual(report["total_removed"], 138 + 2 * floating_count)
                self.assertTrue(all(check["remaining_high_triangle_count"] == 0
                                    for check in report["clearance_sweeps"].values()))
        self.assertEqual(len(outputs), 2)
        self.assertEqual(outputs[0], outputs[1])

    def test_unknown_source_is_rejected_before_writing(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "meshes").mkdir()
            (root / "meshes/rmuc_2026.stl").write_bytes(b"unknown field")
            target = root / "output"
            with patch.multiple(field, SOURCE=root, TARGET=target):
                with self.assertRaisesRegex(RuntimeError, "source STL changed"):
                    field.build()
            self.assertFalse(target.exists())


if __name__ == "__main__":
    unittest.main()
