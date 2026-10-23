#!/usr/bin/env python3
"""Make an optional, nonrendering contact-instrumented model copy for diagnosis."""
from pathlib import Path
import xml.etree.ElementTree as ET
import yaml

T = Path(__file__).resolve().parents[1]


def prepare_contacts(model_path):
    model_path = Path(model_path)
    tree = ET.parse(model_path)
    model = tree.getroot().find('model')
    bridge = yaml.safe_load((T / 'sim/bridge.yaml').read_text())
    topics = []
    for link in model.findall('link'):
        name = link.get('name')
        if name not in ('chassis', 'base_link') and not any(s in name for s in ('wheel_link', 'steer_link')):
            continue
        for collision in link.findall('collision'):
            collision_name = collision.get('name')
            sensor_id = name + '_' + collision_name
            topic = '/diagnostic_contacts/' + sensor_id
            sensor = ET.SubElement(link, 'sensor', name='diagnostic_' + sensor_id, type='contact')
            ET.SubElement(sensor, 'always_on').text = 'true'
            ET.SubElement(sensor, 'update_rate').text = '20'
            ET.SubElement(sensor, 'topic').text = topic
            ET.SubElement(sensor, 'visualize').text = 'false'
            ET.SubElement(ET.SubElement(sensor, 'contact'), 'collision').text = collision_name
            # Gazebo Harmonic Contact system publishes the scoped contact topic
            # even when <sensor><topic> is set; bridge its actual transport name.
            gz_topic = f'/world/default/model/sentry/link/{name}/sensor/diagnostic_{sensor_id}/contact'
            bridge.append(dict(ros_topic_name=topic, gz_topic_name=gz_topic,
                               ros_type_name='ros_gz_interfaces/msg/Contacts',
                               gz_type_name='gz.msgs.Contacts', direction='GZ_TO_ROS'))
            topics.append(topic)
    output = T / 'sim/diagnostic_robot.sdf'
    bridge_path = T / 'sim/diagnostic_bridge.yaml'
    ET.indent(tree)
    tree.write(output, encoding='unicode', xml_declaration=True)
    bridge_path.write_text(yaml.safe_dump(bridge, sort_keys=False))
    return output, bridge_path, topics
