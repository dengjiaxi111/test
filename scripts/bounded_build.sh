#!/usr/bin/env bash
# 仅构建隔离test；make/ninja/colcon均限制为一个任务。
set -euo pipefail
TASK_ROOT=$(cd "$(dirname "$0")/.." && pwd)
cd "$TASK_ROOT"
exec 9>"$TASK_ROOT/.build.lock"
flock -n 9 || { echo '另一个隔离构建正在运行'; exit 1; }
AVAILABLE_KB=$(awk '/MemAvailable:/{print $2}' /proc/meminfo)
((AVAILABLE_KB > 3000000)) || { echo '可用内存不足3GB，不启动构建'; exit 1; }
set +u
source /opt/ros/jazzy/setup.bash
if [[ -f "$TASK_ROOT/install/local_setup.bash" ]]; then source "$TASK_ROOT/install/local_setup.bash"; fi
set -u
export CMAKE_BUILD_PARALLEL_LEVEL=1 MAKEFLAGS=-j1 OMP_NUM_THREADS=1 OPENBLAS_NUM_THREADS=1
export ACADOS_SOURCE_DIR=/home/dengjiaxi/dependency/acados
export CUDA_VISIBLE_DEVICES=''
TASK_CPU=$(python3 -c 'import os; print(min(os.sched_getaffinity(0)))')
# 每个子进程虚拟地址空间上限2.5GiB，单核低优先级；禁止外层无界并行。
ulimit -v 2621440
exec nice -n 15 taskset -c "$TASK_CPU" colcon build --executor sequential \
  --packages-select "$@" --cmake-args -DBUILD_TESTING=OFF \
  -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_CXX_FLAGS_RELWITHDEBINFO='-O2 -g1 -DNDEBUG' \
  -DACADOS_SOURCE_DIR="$ACADOS_SOURCE_DIR" --event-handlers console_direct+
