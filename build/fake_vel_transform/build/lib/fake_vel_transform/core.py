"""ROS-independent geometry and freshness rules. Quaternions are xyzw."""
import math


def normalize(q):
    if not all(math.isfinite(v) for v in q):
        raise ValueError('non-finite quaternion')
    norm = math.sqrt(sum(v * v for v in q))
    if norm < 1e-9:
        raise ValueError('zero quaternion')
    return tuple(v / norm for v in q)


def inverse(q):
    return (-q[0], -q[1], -q[2], q[3])


def rotate(q, v):
    x, y, z, w = q
    vx, vy, vz = v
    tx, ty, tz = 2 * (y*vz-z*vy), 2 * (z*vx-x*vz), 2 * (x*vy-y*vx)
    return (vx+w*tx+y*tz-z*ty, vy+w*ty+z*tx-x*tz, vz+w*tz+x*ty-y*tx)


def fresh(now, stamp, timeout):
    return stamp is not None and 0.0 <= now - stamp <= timeout
