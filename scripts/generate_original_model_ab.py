#!/usr/bin/env python3
"""A/B-only copy of the original swerve physics model; never edits the source."""
from pathlib import Path
import copy
import xml.etree.ElementTree as ET

root = Path(__file__).resolve().parents[2]
test = root / 'test'
source = root / 'navigatiosim2/src/seu_sentry_description/resource/models/new_seu_sentry/seu_sentry.def.xmacro'
block = ET.parse(source).getroot().find('xmacro_define_block')
assert block is not None

sdf = ET.Element('sdf', version='1.9')
model = ET.SubElement(sdf, 'model', name='sentry')
ET.SubElement(model, 'pose').text = '0 0 0.29 0 0 0'
for part in block:
    if part.tag in ('link', 'joint'):
        model.append(copy.deepcopy(part))

# Only resolve visual resource URIs. Original link, collision, mass, inertia,
# wheel joints and gimbal joint are copied without geometric edits.
mesh_root = source.parent / 'meshes'
for uri in model.findall('.//mesh/uri'):
    uri.text = str(mesh_root / Path(uri.text).name)

# The isolated test uses Gazebo truth instead of the original GPU lidar, so
# copy only the original dynamics and joint/odometry systems from the test SDF.
current = ET.parse(test / 'sim/robot.sdf').getroot().find('model')
for plugin in current.findall('plugin'):
    if plugin.findtext('joint_name') != 'lift_joint':
        model.append(copy.deepcopy(plugin))

assert model.find("joint[@name='lift_joint']") is None
assert model.findtext("link[@name='chassis']/inertial/mass") == '12.0'
assert model.findtext("link[@name='chassis']/collision[@name='chassis_main_collision']/geometry/box/size") == '0.43 0.42 0.18'
ET.indent(sdf)
output = test / 'sim/original_robot_ab.sdf'
ET.ElementTree(sdf).write(output, encoding='unicode', xml_declaration=True)
print(output)
