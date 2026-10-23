#!/usr/bin/env python3
"""Build a test-only 2026 field STL without passage roof caps or A-slope floating marks.

The source STL, field SDF, slope surfaces, and side walls remain untouched.
The known source hashes and triangle counts make a changed upstream field fail
closed instead of silently cutting unrelated terrain.
"""

from pathlib import Path
import hashlib
import json
import shutil
import struct

import numpy as np


ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / "navigatiosim2/src/sentry_velocity/gazeboworld/models/rmuc_2026"
TARGET = ROOT / "test/sim/roofless_2026"
# The current source already has both 85-triangle floating marks removed.
# Keep the original export supported for older checkouts as well.
SOURCE_VARIANTS = {
    "aac36b435312fbc5601254d1f502f30ed78447acde86802028e35cc1c7451582": 0,
    "08758108cc78bf64ecc822533a2074ec120287e0eea7bad64188633d92d36daa": 85,
}
RECORD = np.dtype([("normal", "<f4", (3,)), ("vertices", "<f4", (3, 3)), ("attribute", "<u2")])

# Coordinates are in the navigation map: STL xyz * 0.1 + (0, 0, 2).
# A roofs span the narrow y direction. B roofs span the narrow x direction.
# The B cap underside is only z=0.608656 (25 cm above the ground), well below
# its upper shell. Select the complete cap, not just its upper faces/fascia.
# Keep the lower side-wall triangles: the roof is removed, the ramp is not.
ROOFS = {
    "A1": (-5.20, -4.05, -3.80, -3.58, 0.75, "y", 24),
    "A2": (4.05, 5.20, 6.88, 7.08, 0.75, "y", 24),
    "B1": (0.795, 1.01, -4.86, -3.75, 0.60, "x", 50),
    "B2": (-1.01, -0.795, 7.04, 8.15, 0.60, "x", 40),
}

# 60 cm 底盘在四个开口内的实际扫掠区域（地图坐标）。这些区域不能再有
# 高于坡面的洞顶三角面；只检查通道内部，保留两侧护墙和承重坡面。
CLEARANCE_SWEEPS = {
    "A1": (-4.995, -4.394, -3.78, -3.52, 0.60),
    "A2": (4.394, 4.995, 6.81, 7.08, 0.60),
    "B1": (0.74, 1.02, -4.606, -4.006, 0.60),
    "B2": (-1.00, -0.74, 7.304, 7.904, 0.60),
}


def build() -> None:
    source_mesh = SOURCE / "meshes/rmuc_2026.stl"
    data = source_mesh.read_bytes()
    source_hash = hashlib.sha256(data).hexdigest()
    if source_hash not in SOURCE_VARIANTS:
        raise RuntimeError("2026 source STL changed; reidentify the four roof caps before cutting")
    expected_floating = SOURCE_VARIANTS[source_hash]
    count = struct.unpack_from("<I", data, 80)[0]
    if len(data) != 84 + count * RECORD.itemsize:
        raise RuntimeError("unexpected binary STL layout")

    records = np.frombuffer(data, dtype=RECORD, count=count, offset=84)
    vertices = records["vertices"].astype(np.float64) * 0.1
    vertices[:, :, 2] += 2.0
    remove = np.zeros(count, dtype=bool)
    removed_counts = {}

    for name, (xmin, xmax, ymin, ymax, roof_z, axis, expected) in ROOFS.items():
        inside = (
            (vertices[:, :, 0].min(axis=1) > xmin)
            & (vertices[:, :, 0].max(axis=1) < xmax)
            & (vertices[:, :, 1].min(axis=1) > ymin)
            & (vertices[:, :, 1].max(axis=1) < ymax)
        )
        roof = vertices[:, :, 2].min(axis=1) >= roof_z
        selected = inside & roof
        if selected.sum() != expected or np.any(remove & selected):
            raise RuntimeError(f"{name}: expected {expected} distinct roof triangles, found {selected.sum()}")
        remove |= selected
        removed_counts[name] = int(selected.sum())

    if remove.sum() != 138 or np.any(vertices[remove, :, 2].min(axis=1) < 0.60):
        raise RuntimeError("roof selection overlaps the drivable slope")

    # 两个 A 坡的悬空标识薄片：法向距承重坡面约 2.4 cm，厚约 1 mm。
    # 地图坐标单位为米；同时删除上下表面及封边，保留坡面和贴坡标线。
    floating_counts = {}
    for name, bounds, direction, low, high in (
        ("A1", (-4.87, -4.46, -3.48, -3.32), 1, -0.4111, -0.4097),
        ("A2", (4.46, 4.87, 6.61, 6.77), -1, -1.2623, -1.2609),
    ):
        xmin, xmax, ymin, ymax = bounds
        plane = (vertices[:, :, 2] * np.cos(np.pi / 12)
                 + direction * vertices[:, :, 1] * np.sin(np.pi / 12))
        floating = (
            (vertices[:, :, 0].min(axis=1) > xmin)
            & (vertices[:, :, 0].max(axis=1) < xmax)
            & (vertices[:, :, 1].min(axis=1) > ymin)
            & (vertices[:, :, 1].max(axis=1) < ymax)
            & (plane.min(axis=1) > low)
            & (plane.max(axis=1) < high)
        )
        if int(floating.sum()) != expected_floating or np.any(remove & floating):
            raise RuntimeError(f"{name}: expected {expected_floating} distinct floating-mark triangles, found {floating.sum()}")
        remove |= floating
        floating_counts[name] = int(floating.sum())

    kept_vertices = vertices[~remove]
    clearances = {}
    for name, (xmin, xmax, ymin, ymax, roof_z) in CLEARANCE_SWEEPS.items():
        # Bounding-box overlap is deliberately stricter than a centerline ray:
        # it also catches a leftover roof edge that could touch the chassis side.
        residual = (
            (kept_vertices[:, :, 0].max(axis=1) > xmin)
            & (kept_vertices[:, :, 0].min(axis=1) < xmax)
            & (kept_vertices[:, :, 1].max(axis=1) > ymin)
            & (kept_vertices[:, :, 1].min(axis=1) < ymax)
            & (kept_vertices[:, :, 2].max(axis=1) > roof_z)
        )
        if np.any(residual):
            raise RuntimeError(f"{name}: {int(residual.sum())} high triangles remain inside the passage")
        clearances[name] = {"sweep_bounds_xy_m": [xmin, xmax, ymin, ymax],
                            "check_above_world_z_m": roof_z,
                            "remaining_high_triangle_count": int(residual.sum())}

    destination_mesh = TARGET / "meshes/rmuc_2026.stl"
    destination_mesh.parent.mkdir(parents=True, exist_ok=True)
    kept = records[~remove]
    destination_mesh.write_bytes(data[:80] + struct.pack("<I", len(kept)) + kept.tobytes())
    shutil.copyfile(SOURCE / "model.sdf", TARGET / "model.sdf")
    shutil.copyfile(SOURCE / "model.config", TARGET / "model.config")
    report = {"source_sha256": source_hash, "source_triangle_count": count,
              "removed_cap_triangles": removed_counts,
              "removed_floating_mark_triangles": floating_counts, "total_removed": int(remove.sum()),
              "minimum_removed_world_z_m": float(vertices[remove, :, 2].min()),
              "all_other_triangles_preserved_verbatim": True,
              "clearance_sweeps": clearances}
    report_path = ROOT / "test/results/roofless_geometry.json"
    report_path.parent.mkdir(parents=True, exist_ok=True)
    report_path.write_text(json.dumps(report, indent=2) + "\n")
    print("2026 test field: removed A1=24 A2=24 B1=50 B2=40 cap triangles including B undersides; "
          f"removed A1={floating_counts['A1']} A2={floating_counts['A2']} floating-mark triangles; "
          "all four 60 cm clearance sweeps clear; slopes retained")


if __name__ == "__main__":
    build()
