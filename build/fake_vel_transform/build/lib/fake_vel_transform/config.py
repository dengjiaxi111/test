"""Read the SAME selected YAML as nav_server, including CLI params-file overrides."""
import math
import yaml


def feedback_policy(path):
    with open(path, encoding='utf-8') as stream:
        data = yaml.safe_load(stream)
    params = data['nav_server']['ros__parameters']
    nmpc = params.get('nmpc', {})
    alpha = float(params.get('nmpc.odom_feedback_alpha', nmpc.get('odom_feedback_alpha', 0.8)))
    timeout = float(params.get('nmpc.chassis_velocity_timeout_sec', nmpc.get('chassis_velocity_timeout_sec', 0.15)))
    if not math.isfinite(alpha) or not 0 <= alpha <= 1:
        raise ValueError('odom_feedback_alpha must be in [0,1]')
    if not math.isfinite(timeout) or timeout <= 0:
        raise ValueError('feedback timeout must be positive')
    return {'odom_feedback_alpha': alpha, 'feedback_timeout': timeout}
