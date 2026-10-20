"""Omnidirectional double integrator. State is measured/estimated p,v, not commands."""
import casadi as ca
import numpy as np

NX, NU, NP = 4, 2, 18
DT, N = 0.02, 75
# Must match omni_model.hpp Parameter.
PARAM_NAMES = (
    "xref", "yref", "vxref", "vyref", "tx", "ty",
    "distance", "anchor_x", "anchor_y", "grad_x", "grad_y",
    "q_position", "q_velocity", "r_acceleration", "q_contour",
    "q_obstacle", "safe_distance", "weight_scale",
)

class OmniModel:
    def __init__(self):
        self.state = ca.SX.sym("x", NX)
        self.control = ca.SX.sym("u", NU)
        self.params = ca.SX.sym("p", NP)

    def dynamics(self):
        x, u = self.state, self.control
        return ca.vertcat(x[:2] + DT*x[2:] + 0.5*DT**2*u, x[2:] + DT*u)

    def costs(self):
        x, u, p = self.state, self.control, self.params
        error = x[:2] - p[:2]
        contour = -p[5]*error[0] + p[4]*error[1]
        distance = p[6] + p[9]*(x[0]-p[7]) + p[10]*(x[1]-p[8])
        violation = ca.fmax(0, p[16] - distance)
        tracking = p[17]*(p[11]*ca.sumsqr(error)
            + p[12]*ca.sumsqr(x[2:]-p[2:4])
            + p[14]*contour**2 + p[15]*violation**2)
        return tracking + p[13]*ca.sumsqr(u), tracking

    @staticmethod
    def defaults():
        return np.array([0,0,0,0,1,0, 10,0,0,0,0, 3,0.1,0.01,25,70,0.5,1], dtype=float)
