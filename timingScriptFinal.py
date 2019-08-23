import argparse
import os, sys
import shlex, subprocess
from subprocess import PIPE, TimeoutExpired

# constants
EQ      = 'equiv'
NEQ     = 'not equiv'
UNKNOWN = 'unknown'
ERROR   = 'error'
TIMEOUT   = 300

parser = argparse.ArgumentParser()
parser.add_argument('--CC2', action='store_true', default=False, help ="enable CC2 measurements (Docker environment assumed)" )
parser.add_argument('--CLEVER', action='store_true', default=False, help ="enable CLEVER measurements (Docker environment assumed)" )
parser.add_argument('--REVE', action='store_true', default=False, help ="enable REVE measurements (Reve Docker environment assumed)" )

io_args = parser.parse_args()
enableCC2 = io_args.CC2
enableCLEVER = io_args.CLEVER
enableREVE = io_args.REVE


for dirpath, dnames, fnames in os.walk("./"):
    dnames.sort()
    #print(dirpath)
    if len(dirpath.split("/")) != 4:
        continue
    if "/libA" not in dirpath or ("/mergedHard" not in dirpath and "/nestedMerge" not in dirpath) or "mergedHard_CallMerge" in dirpath:
        continue
    #if "/multLibs" not in dirpath:
    #    continue
    if "EXTRA_prime_sum" in dirpath:
        continue
    #if "eq/" not in dirpath and "extras" not in dirpath:
    #    continue

    dirname = dirpath.split("/")[-1]
    c_files = [f for f in fnames if f.endswith(".c")]
    py_files = [f for f in fnames if f.endswith(".py")]
    if (len(c_files) != 2):
        print("Skipped: %s", dirpath)
        continue
    
    c_files.sort()
    old_c = c_files[0]; new_c = c_files[1]
    if old_c == "new.c":
        temp = old_c; old_c = new_c; new_c = temp
    old_c_filename = os.path.join(dirpath, old_c)
    new_c_filename = os.path.join(dirpath, new_c)

    c_clientlib_names = [("clientmain", "foo"), ("main", "foo"), ("clientmain", "lib"), ("client", "lib"), ("client", "foo"), (dirname, "lib")]
    args = shlex.split("cat %s" % old_c_filename)
    proc = subprocess.Popen(args, stdout=PIPE, stderr=PIPE)
    out, err = proc.communicate(timeout=300)
    strout = out.decode('utf8')

    c_client = None; c_lib = None
    for cname, lname in c_clientlib_names:
        if cname in strout and lname in strout:
            c_client = cname
            c_lib = lname
            break

    REVE_RESULT = UNKNOWN
    CC2_RESULT = UNKNOWN
    CC2_CONC_RESULT = UNKNOWN
    KLEECLEVER_RESULT = UNKNOWN
    CC2_TIME = 0
    CC2_CONC_TIME = 0
    CLEVER_TIME = 0
    KLEECLEVER_TIME = 0
    REVE_TIME = 0
    CC2_KLEE_TIME = 0
    CC2_SOLVE_TIME = 0
    CC2_CONC_SOLVE_TIME = 0

    if enableCC2:
        try:
          #TODO: WARNING - STATIC PATH ARGUMENT
          args = shlex.split("runlim -s 10000 -o loggingOut/%s.runlimCC2 time -p CC2 --old %s --new %s \
                     --client %s --lib %s --hybrid-solving=True" 
                      % (dirpath.split("/")[-2]+dirpath.split("/")[-1], old_c_filename, new_c_filename, c_client, c_lib))
          proc = subprocess.Popen(args, stdout=PIPE, stderr=PIPE)
          out, err = proc.communicate(timeout=TIMEOUT)
          out_lines = out.decode('utf8').split('\n')
          err_lines = err.decode('utf8').split('\n')
          for line in out_lines:
              if "error" in line:
                  CC2_RESULT = ERROR
          for line in out_lines:
              if "Grow out of context, CEX" in line:
                  CC2_RESULT = NEQ
              elif "have been checked, CSE" in line:
                  CC2_RESULT = EQ
              elif "Solver decision Time:" in line:
                  CC2_SOLVE_TIME = float(line.lstrip("Solver decision Time: ").rstrip())
              elif "Total Checking Time:" in line:
                  CC2_TIME = -1 #float(line.lstrip("Total Checking Time: ").rstrip())
          if "real " in err_lines[-4]: #more robust?
              CC2_TIME = float(err_lines[-4].split()[1])
        except TimeoutExpired:
            proc.kill()
            #out, err = proc.communicate()
            args = shlex.split("./kill_procs.sh") 
            kill = subprocess.Popen(args, stdout=PIPE, stderr=PIPE, shell=True)
            out, err = kill.communicate(timeout=TIMEOUT)
            CC2_RESULT = "timeout"
            CC2_TIME   = TIMEOUT

    """
    if enableCC2_Conc:
        try: 
          #TODO: WARNING - STATIC PATH ARGUMENT
          args = shlex.split("CC2 --old %s --new %s \
                     --client %s --lib %s --hybrid-solving=True --concurrent=True" 
                      % (old_c_filename, new_c_filename, c_client, c_lib))
          proc = subprocess.Popen(args, stdout=PIPE, stderr=PIPE)
          out, err = proc.communicate(timeout=TIMEOUT)
          out_lines = out.decode('utf8').split('\n')
          #err_lines = err.decode('utf8').split('\n')
          for line in out_lines:
              if "error" in line:
                  CC2_CONC_RESULT = ERROR
          for line in out_lines:
              if "Grow out of context, CEX" in line:
                  CC2_CONC_RESULT = NEQ
              elif "have been checked, CSE" in line:
                  CC2_CONC_RESULT = EQ
              elif "Solver decision Time:" in line:
                  CC2_CONC_SOLVE_TIME = float(line.lstrip("Solver decision Time: ").rstrip())
                  #KLEECLEVER_TIME = float(line.lstrip("Solver decision Time: ").rstrip())
              elif "Total Checking Time:" in line:
                  CC2_CONC_TIME = float(line.lstrip("Total Checking Time: ").rstrip())
          #for line in err_lines:
          #    if "Command exited with non-zero" in line:
          #        CC2_CONC_RESULT = ERROR
          #if "real " in err_lines[-4]: #more robust?
          #    CC2_CONC_TIME = float(err_lines[-4].split()[1])
        except TimeoutExpired:
            proc.kill()
            #out, err = proc.communicate()
            args = shlex.split("./kill_procs.sh") 
            kill = subprocess.Popen(args, stdout=PIPE, stderr=PIPE, shell=True)
            out, err = kill.communicate(timeout=TIMEOUT)
            CC2_CONC_RESULT = "timeout"
            CC2_CONC_TIME = TIMEOUT"""

    if enableCLEVER:
        try:    
          #TODO: WARNING - STATIC PATH ARGUMENT
          args = shlex.split("runlim -s 10000 -o loggingOut/%s.runlimCLEVER time -p CLEVERC --old %s \
                    --new %s --client %s --lib %s" % 
                                (dirpath.split("/")[-2]+dirpath.split("/")[-1], old_c_filename, new_c_filename, c_client, c_lib))
          proc = subprocess.Popen(args, stdout=PIPE, stderr=PIPE)
          out, err = proc.communicate(timeout=TIMEOUT)
          out_lines = out.decode('utf8').split('\n')
          err_lines = err.decode('utf8').split('\n')
          for line in out_lines:
              if "error" in line:
                  KLEECLEVER_RESULT = ERROR
          for line in out_lines:
              if "CEX" in line:
                  KLEECLEVER_RESULT = NEQ
              elif "CSE" in line:
                  KLEECLEVER_RESULT = EQ
              elif "time :" in line:
                  KLEECLEVER_TIME = -1 #float(line.lstrip("time : ").rstrip())
          if "real " in err_lines[-4]:
              KLEECLEVER_TIME = float(err_lines[-4].split()[1])
        
        except TimeoutExpired:
            proc.kill()
            args = shlex.split("./kill_procs.sh") 
            kill = subprocess.Popen(args, stdout=PIPE, stderr=PIPE, shell=True)
            out, err = kill.communicate(timeout=TIMEOUT)
            KLEECLEVER_RESULT = "timeout"
            KLEECLEVER_TIME = TIMEOUT


    if enableREVE:
        try:
            args0 = shlex.split("runlim -s 10000 -o loggingOut/%s.runlimREVE  ../llreve/reve/build/reve/llreve -infer-marks -fun=%s -muz %s %s" % 
                                (dirpath.split("/")[-2]+dirpath.split("/")[-1], c_client, old_c_filename.replace("./", "./reve_"),
                                    new_c_filename.replace("./", "./reve_")) )
            proc0 = subprocess.Popen(args0, stdout=PIPE, stderr=PIPE)
            args = shlex.split("time -p z3 -in ") # -smt2 fixedpoint.engine=duality
            proc = subprocess.Popen(args, stdin=proc0.stdout, stdout=PIPE, stderr=PIPE)
            out, err = proc.communicate(timeout=TIMEOUT)
            out_lines = out.decode('utf8').split('\n')
            err_lines = err.decode('utf8').split('\n')

            if "real " in err_lines[-4]:
              REVE_TIME = float(err_lines[-4].split()[1])
            
            for line in out_lines:
              if "unsat" in line:
                  REVE_RESULT = EQ
                  break
              if "sat" in line:
                  REVE_RESULT = NEQ
            for line in out_lines:
              if "Segmentation" in line:
                  REVE_RESULT = ERROR
            for line in err_lines:
              if "Segmentation" in line:
                  REVE_RESULT = ERROR
        except TimeoutExpired:
            proc.kill()
            args = shlex.split("./kill_procs.sh") 
            kill = subprocess.Popen(args, stdout=PIPE, stderr=PIPE, shell=True)
            out, err = kill.communicate(timeout=TIMEOUT)
            REVE_RESULT = "timeout"
            REVE_TIME   = TIMEOUT

    print("%-20s , %s; %-8.4f , %s; %-8.4f , %s; %-8.4f" %(dirpath, CC2_RESULT, CC2_TIME, KLEECLEVER_RESULT, KLEECLEVER_TIME, REVE_RESULT, REVE_TIME))
