#!/usr/bin/env bash
# 独立模型+测试版navigate；原仿真入口和原navigate不变。
set -euo pipefail
TASK_ROOT=$(cd "$(dirname "$0")" && pwd)
cd "$TASK_ROOT/.."
set +u
source /opt/ros/jazzy/setup.bash
source "$TASK_ROOT/install/local_setup.bash"
set -u
export LD_LIBRARY_PATH="/home/dengjiaxi/dependency/acados/lib:${LD_LIBRARY_PATH:-}"
exec /usr/bin/python3 "$TASK_ROOT/scripts/run_case.py" \
  --case crest --gui --manual --render nvidia --max-wall 3600 "$@"
