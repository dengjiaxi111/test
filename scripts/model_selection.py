"""Select an existing test model before starting Gazebo or ROS processes."""
from dataclasses import dataclass
from pathlib import Path
import xml.etree.ElementTree as ET

T = Path(__file__).resolve().parents[1]
MODELS = {
    1: ('原舵轮模型（无升降，仅运动对照）', T / 'sim/original_robot_ab.sdf'),
    2: ('60×60cm 底盘＋原云台（带升降）', T / 'sim/robot.sdf'),
    3: ('45×45cm 简化底盘＋简化云台（带升降）', T / 'sim/simplified_robot.sdf'),
}


@dataclass(frozen=True)
class ModelChoice:
    number: int | None
    label: str
    path: Path
    has_lift: bool


def select_model(number=None, custom_path=None, *, interactive=False):
    if number is not None and custom_path is not None:
        raise ValueError('--model 和 --model-sdf 不能同时使用')
    if number is None and custom_path is None:
        number = 2
        if interactive:
            print('启动前选择模型：', flush=True)
            for key, (label, _) in MODELS.items():
                print(f'  {key}. {label}', flush=True)
            while True:
                try:
                    value = input('模型 [1/2/3，回车默认2]：').strip()
                except EOFError:
                    value = ''
                if value in ('', '1', '2', '3'):
                    number = int(value or '2')
                    break
                print('请输入 1、2 或 3。', flush=True)
    if custom_path is not None:
        path = Path(custom_path).resolve()
        label = '自定义模型'
    else:
        label, path = MODELS[number]
    model = ET.parse(path).getroot().find('model')
    if model is None or model.get('name') != 'sentry':
        raise ValueError(f'模型必须包含 name="sentry"：{path}')
    has_lift = model.find("joint[@name='lift_joint']") is not None
    return ModelChoice(number, label, path, has_lift)
