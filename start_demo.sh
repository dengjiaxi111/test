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
# 默认使用本轮验收的模型3；显式模型参数仍可覆盖。
model_args=(--model 3)
for arg in "$@"; do
  case "$arg" in
    --model|--model=*|--model-sdf|--model-sdf=*) model_args=(); break ;;
  esac
done
exec /usr/bin/python3 "$TASK_ROOT/scripts/run_case.py" \
  --case upper_approach --gui --manual --render nvidia --max-wall 3600 "${model_args[@]}" "$@"
