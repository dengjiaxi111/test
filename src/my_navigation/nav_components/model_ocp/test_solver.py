"""Numerical tests against the generated native solver, not a substitute model."""
import time
from pathlib import Path
import casadi as ca
import numpy as np
from acados_template import AcadosOcpSolver
from export_ocp import create_ocp
from model import OmniModel, DT, N


def main():
    model = OmniModel()
    dynamics = ca.Function('step', [model.state, model.control], [model.dynamics()])
    x, a = np.array([1,2,3,-4.]), np.array([2,1.])
    np.testing.assert_allclose(np.asarray(dynamics(x,a)).ravel(),
        np.r_[x[:2]+DT*x[2:]+0.5*DT**2*a, x[2:]+DT*a])
    output = Path(__file__).resolve().parent.parent/'nmpc_solver_omni'
    solver = AcadosOcpSolver(create_ocp(output), json_file=str(output/'acados_ocp.json'), generate=False, build=False)
    timings = []
    for direction in ([1.,0.], [0.,1.], [2**-0.5,2**-0.5]):
        direction = np.array(direction)
        solver.reset()
        initial = np.zeros(4)
        for i in range(N+1):
            p = model.defaults()
            p[:2] = i*DT*direction
            p[2:4] = direction
            p[4:6] = direction
            p[15] = 0
            solver.set(i,'p',p)
            solver.set(i,'x',initial)
            if i<N:
                solver.set(i,'u',np.zeros(2))
        solver.set(0,'lbx',initial)
        solver.set(0,'ubx',initial)
        # SQP_RTI refinement for nonlinear norm constraints; report required passes.
        for iteration in range(8):
            start = time.perf_counter()
            status = solver.solve()
            timings.append((time.perf_counter()-start)*1000)
            assert status == 0, status
            states = np.array([solver.get(i,'x') for i in range(N+1)])
            controls = np.array([solver.get(i,'u') for i in range(N)])
            if np.max(np.linalg.norm(controls,axis=1))<=4.001 and np.max(np.linalg.norm(states[1:,2:],axis=1))<=2.001:
                break
        assert iteration<7, 'norm constraints did not converge'
        assert np.isfinite(states).all() and np.isfinite(controls).all()
        for i in range(N):
            np.testing.assert_allclose(states[i+1],np.asarray(dynamics(states[i],controls[i])).ravel(),atol=1e-5)
        assert np.dot(states[1,2:],direction)>0.01
        assert abs(np.cross(direction,states[1,2:]))<1e-5
        print(f'direction={direction} RTI passes={iteration+1} first_velocity={states[1,2:]}')
    for scenario in ('curve', 'brake_with_lateral_velocity'):
        solver.reset()
        initial = np.array([0.,0.,1.,0.]) if scenario=='curve' else np.array([0.,0.,0.7,-0.3])
        for i in range(N+1):
            p = model.defaults()
            if scenario=='curve':
                t=i*DT
                p[:4]=[np.sin(t),1-np.cos(t),np.cos(t),np.sin(t)]
                p[4:6]=[np.cos(t),np.sin(t)]
            p[15]=0
            solver.set(i,'p',p)
            solver.set(i,'x',initial)
            if i<N: solver.set(i,'u',np.zeros(2))
        solver.set(0,'lbx',initial)
        solver.set(0,'ubx',initial)
        for iteration in range(8):
            assert solver.solve()==0
            states=np.array([solver.get(i,'x') for i in range(N+1)])
            controls=np.array([solver.get(i,'u') for i in range(N)])
            if np.max(np.linalg.norm(controls,axis=1))<=4.001 and np.max(np.linalg.norm(states[1:,2:],axis=1))<=2.001:
                break
        assert iteration<7
        for i in range(N):
            np.testing.assert_allclose(states[i+1],np.asarray(dynamics(states[i],controls[i])).ravel(),atol=1e-5)
        if scenario=='curve':
            assert states[-1,1]>0.3
        else:
            assert np.dot(controls[0],initial[2:])<0
            assert np.linalg.norm(states[-1,2:])<np.linalg.norm(initial[2:])
        print(f'{scenario}: passes={iteration+1}, terminal={states[-1]}')
    for _ in range(100):
        start = time.perf_counter()
        assert solver.solve() == 0
        timings.append((time.perf_counter()-start)*1000)
        assert np.isfinite(solver.get(0,'u')).all()
        assert np.linalg.norm(solver.get(0,'u')) <= 4.001
    print(f'Native solver passes: {len(timings)}, mean={np.mean(timings):.3f}ms, '
          f'p95={np.percentile(timings,95):.3f}ms, max={max(timings):.3f}ms')

if __name__=='__main__':
    main()
