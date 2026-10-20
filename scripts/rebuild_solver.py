#!/usr/bin/env python3
"""仅为本机acados兼容性重编译原CasADi代码，不增加模型、代价或约束。"""
from pathlib import Path
import subprocess,resource,os,shutil,hashlib,json
T=Path(__file__).resolve().parents[1];D=T/'src/my_navigation/nav_components/nmpc_solver_omni';A=Path('/home/dengjiaxi/dependency/acados')
resource.setrlimit(resource.RLIMIT_AS,(1800*1024**2,1800*1024**2));os.nice(15);os.sched_setaffinity(0,{min(os.sched_getaffinity(0))})
p=D/'acados_solver_omni_nmpc.c';s=p.read_text()
# Current acados splits forward/adjoint sensitivity options. Both disabled in original;
# rename only the disabled forward flag, leaving adjoint at its disabled default.
s=s.replace('"with_solution_sens_wrt_params",','"with_solution_sens_wrt_params_forw",')
p.write_text(s)
b=T/'build/solver_compat';b.mkdir(parents=True,exist_ok=True)
files=[p]+sorted(D.glob('*/*.c'));objs=[]
for i,f in enumerate(files):
    out=b/(f.stem+'.o')
    subprocess.run(['cc','-std=c99','-O2','-fPIC','-I'+str(D),'-I'+str(A/'include'),'-I'+str(A/'include/blasfeo/include'),'-I'+str(A/'include/hpipm/include'),'-c',str(f),'-o',str(out)],check=True)
    objs.append(str(out));print(i+1,'/',len(files),f.name,flush=True)
out=b/'libacados_ocp_solver_omni_nmpc.so'
subprocess.run(['cc','-shared','-o',str(out),*objs,'-L'+str(A/'lib'),'-lacados','-lhpipm','-lblasfeo','-lm','-Wl,-rpath,'+str(A/'lib')],check=True)
for dest in (D/out.name,T/'install/nav_components/lib'/out.name):shutil.copy2(out,dest)
(T/'results/solver_compat.json').write_text(json.dumps({'rebuilt_sources':len(files),'casadi_mathematical_sources_unchanged':True,'compatibility_change':'disabled sensitivity option renamed to _forw','execution_constraint_change':'none; original generated dimensions and constraints restored','sha256':hashlib.sha256(out.read_bytes()).hexdigest()},indent=2))
