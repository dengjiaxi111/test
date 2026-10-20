"""Generate and build only the omni solver; no silent fallback to wheelleg."""
import argparse
from pathlib import Path
import casadi as ca
import numpy as np
from acados_template import AcadosOcp, AcadosOcpSolver
from model import OmniModel, NX, NU, NP, DT, N

def create_ocp(output_dir):
    model = OmniModel()
    ocp = AcadosOcp()
    ocp.model.name = "omni_nmpc"
    ocp.model.x, ocp.model.u, ocp.model.p = model.state, model.control, model.params
    ocp.model.disc_dyn_expr = model.dynamics()
    ocp.solver_options.integrator_type = "DISCRETE"
    ocp.solver_options.N_horizon = N
    ocp.solver_options.tf = N*DT
    stage, terminal = model.costs()
    ocp.cost.cost_type_0 = ocp.cost.cost_type = ocp.cost.cost_type_e = "EXTERNAL"
    ocp.model.cost_expr_ext_cost_0 = stage
    ocp.model.cost_expr_ext_cost = stage
    ocp.model.cost_expr_ext_cost_e = terminal
    ocp.parameter_values = model.defaults()
    ocp.constraints.x0 = np.zeros(NX)
    # Initial measured velocity is an equality, never silently clipped to a bound.
    # First acceleration only; later stages constrain speed and acceleration.
    ocp.model.con_h_expr_0 = ca.vertcat(ca.sumsqr(model.control))
    ocp.constraints.lh_0 = np.array([-1e10])
    ocp.constraints.uh_0 = np.array([16.0])
    ocp.model.con_h_expr = ca.vertcat(ca.sumsqr(model.state[2:]), ca.sumsqr(model.control))
    ocp.constraints.lh = np.array([-1e10, -1e10])
    ocp.constraints.uh = np.array([4.0, 16.0])
    ocp.model.con_h_expr_e = ca.vertcat(ca.sumsqr(model.state[2:]))
    ocp.constraints.lh_e, ocp.constraints.uh_e = np.array([-1e10]), np.array([4.0])
    ocp.solver_options.qp_solver = "PARTIAL_CONDENSING_HPIPM"
    ocp.solver_options.qp_solver_cond_N = 25
    ocp.solver_options.hessian_approx = "EXACT"
    ocp.solver_options.nlp_solver_type = "SQP_RTI"
    ocp.solver_options.qp_solver_iter_max = 50
    ocp.solver_options.levenberg_marquardt = 1e-4
    # Default acados stage scaling is dt and terminal scaling is 1.
    ocp.code_export_directory = str(Path(output_dir).resolve())
    return ocp

def export(output_dir):
    directory = Path(output_dir).resolve()
    directory.mkdir(parents=True, exist_ok=True)
    solver = AcadosOcpSolver(create_ocp(directory), json_file=str(directory/"acados_ocp.json"))
    print(f"Generated omni_nmpc NX={NX}, NU={NU}, NP={NP}, N={N}, dt={DT}")
    return solver

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--output-dir", default=str(Path(__file__).resolve().parent.parent/"nmpc_solver_omni"))
    export(parser.parse_args().output_dir)
