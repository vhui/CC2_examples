import os, sys
import shlex, subprocess
from subprocess import PIPE, TimeoutExpired

#import matplotlib.pyplot as plt
#import numpy as np
#import pickle




# constants
EQ      = 'equiv'
NEQ     = 'not equiv'
UNKNOWN = 'unknown'
ERROR   = 'error'
TIMEOUT   = 300
CC2_RESULT = UNKNOWN
CC2_CBMC_RESULT = UNKNOWN
CC2_SEA_RESULT = UNKNOWN
CC2_KLEE_RESULT = UNKNOWN
CLEVER_RESULT = UNKNOWN
KLEECLEVER_RESULT = UNKNOWN
CC2_TIME = 0
CC2_CBMC_TIME = 0
CC2_SEA_TIME = 0
CC2_KLEE_TIME = 0
CLEVER_TIME = 0
KLEECLEVER_TIME = 0
CC2_SOLVE_TIME = 0
CC2_SEA_SOLVE_TIME = 0
CC2_CBMC_SOLVE_TIME = 0
CC2_KLEE_SOLVE_TIME = 0

REPEATS = 5
UNWINDS = 1000

start = False

for dirpath, dnames, fnames in os.walk("./"):
  #for dirname in sorted(dnames):
    dnames.sort()
    #print(dirpath)
    if len(dirpath.split("/")) != 3: #not inside gen folder!
        continue
    """if "multLibs" not in dirpath:
        continue"""
    if "eq/" not in dirpath and "extras" not in dirpath:
        continue
    dirname = dirpath.split("/")[-1]
    """if "loopmult" not in dirpath and "LoopMult" not in dirpath and "loopunreach" not in dirpath and "LoopUnreach" not in dirpath:
        continue"""
    """if "loopmult" in dirpath or "LoopMult" in dirpath or "loopunreach" in dirpath or "LoopUnreach" in dirpath:
        continue"""
    """if dirpath != "./extras/prime_sum":
        continue"""
    """if dirpath == "./merged/EQ_ltfiveBoundEQ_LoopUnreach2/back":
        start = True
    if not start:
        continue"""
    #if "EQ_LoopMult" in dirpath or "EQ_LoopUnreach" in dirpath:
    #    continue
    c_files = [f for f in fnames if f.endswith(".c")]
    py_files = [f for f in fnames if f.endswith(".py")]
    if (len(c_files) != 2):
        print("Skipped: %s", dirpath)
        continue
    """if (len(c_files) != 2 or len(py_files) != 2):
        print("Skipped: %s", dirpath)
        continue"""
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
    """if not c_client or not c_lib:
      print("Error %s" % dirpath)
      print("C files:\nOld: %s\tNew: %s" % (old_c, new_c))
      print(c_client, c_lib)"""
      #import pdb; pdb.set_trace()
    

    """gendir = dirpath + "/gen"
    os.mkdir(gendir)

    args = shlex.split("python3 gen_self.py --new %s --old %s --client %s --gen_new %s --gen_old %s" % (new_c_filename, old_c_filename, c_client, gendir + "/new.c", gendir + "/old.c"))
    proc = subprocess.Popen(args, stdout=PIPE, stderr=PIPE)
    out, err = proc.communicate(timeout=300)
    strout = out.decode('utf8')
    #import pdb; pdb.set_trace()
    continue"""

    CC2_RESULT = UNKNOWN
    CC2_SEA_RESULT = UNKNOWN
    CC2_CBMC_RESULT = UNKNOWN
    CC2_CONC_RESULT = UNKNOWN
    CLEVER_RESULT = UNKNOWN
    KLEECLEVER_RESULT = UNKNOWN
    CC2_KLEE_RESULT = UNKNOWN
    CC2_TIME = 0
    CC2_SEA_TIME = 0
    CC2_CBMC_TIME = 0
    CC2_CONC_TIME = 0
    CLEVER_TIME = 0
    KLEECLEVER_TIME = 0
    CC2_KLEE_TIME = 0
    CC2_SOLVE_TIME = 0
    CC2_SEA_SOLVE_TIME = 0
    CC2_CONC_SOLVE_TIME = 0

    try:    
      #TODO: WARNING - STATIC PATH ARGUMENT
      args = shlex.split("CC2 --old %s --new %s \
                 --client %s --lib %s --hybrid-solving=True" 
                  % (old_c_filename, new_c_filename, c_client, c_lib))
      proc = subprocess.Popen(args, stdout=PIPE, stderr=PIPE)
      out, err = proc.communicate(timeout=TIMEOUT)
      out_lines = out.decode('utf8').split('\n')
      #err_lines = err.decode('utf8').split('\n')
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
              CC2_TIME = float(line.lstrip("Total Checking Time: ").rstrip())
      #if "real " in err_lines[-4]: #more robust?
      #    CC2_TIME = float(err_lines[-4].split()[1])
    except TimeoutExpired:
        proc.kill()
        #out, err = proc.communicate()
        args = shlex.split("./kill_procs.sh") 
        kill = subprocess.Popen(args, stdout=PIPE, stderr=PIPE, shell=True)
        out, err = kill.communicate(timeout=TIMEOUT)
        CC2_RESULT = "timeout"
        CC2_TIME   = TIMEOUT
 
    """try:    
      #TODO: WARNING - STATIC PATH ARGUMENT
      args = shlex.split("/usr/bin/time -p python3 ../CC2/CC2/checker.py --old %s --new %s \
                 --client %s --lib %s --unwind %d --engine %s" 
                  % (old_c_filename, new_c_filename, c_client, c_lib, UNWINDS, "SEAHORN"))
      proc = subprocess.Popen(args, stdout=PIPE, stderr=PIPE)
      out, err = proc.communicate(timeout=TIMEOUT)
      out_lines = out.decode('utf8').split('\n')
      err_lines = err.decode('utf8').split('\n')
      for line in out_lines:
          if "error" in line:
              CC2_SEA_RESULT = ERROR
      for line in out_lines:
          if "Grow out of context, CEX" in line:
              CC2_SEA_RESULT = NEQ
          elif "have been checked, CSE" in line:
              CC2_SEA_RESULT = EQ
          elif "Solver decision Time:" in line:
              CC2_SEA_SOLVE_TIME = float(line.lstrip("Solver decision Time: ").rstrip())
          elif "Total Checking Time:" in line:
              CC2_SEA_TIME = float(line.lstrip("Total Checking Time: ").rstrip())
      #if "real " in err_lines[-4]: #more robust?
      #    CC2_SEA_TIME = float(err_lines[-4].split()[1])
      #for line in err_lines:
      #    if "Command exited with non-zero" in line:
      #        CC2_SEA_RESULT = ERROR
    except TimeoutExpired:
        proc.kill()
        #out, err = proc.communicate()
        args = shlex.split("./kill_procs.sh") 
        kill = subprocess.Popen(args, stdout=PIPE, stderr=PIPE, shell=True)
        out, err = kill.communicate(timeout=TIMEOUT)
        CC2_SEA_RESULT = "timeout"
        CC2_SEA_TIME   = TIMEOUT"""

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
        CC2_CONC_TIME = TIMEOUT

    """try:    
      #TODO: WARNING - STATIC PATH ARGUMENT
      args = shlex.split("/usr/bin/time -p python3  ../CC2/CC2/checker.py --old %s --new %s \
                 --client %s --lib %s --engine %s" 
                  % (old_c_filename, new_c_filename, c_client, c_lib, "KLEE"))
      proc = subprocess.Popen(args, stdout=PIPE, stderr=PIPE)
      out, err = proc.communicate(timeout=TIMEOUT)
      out_lines = out.decode('utf8').split('\n')
      err_lines = err.decode('utf8').split('\n')
      for line in out_lines:
          if "Grow out of context, CEX" in line:
              CC2_KLEE_RESULT = NEQ
          elif "have been checked, CSE" in line:
              CC2_KLEE_RESULT = EQ
          elif "Solver decision Time:" in line:
              CC2_KLEE_SOLVE_TIME = float(line.lstrip("Solver decision Time: ").rstrip())
      if "real " in err_lines[-4]: #more robust?
          CC2_KLEE_TIME = float(err_lines[-4].split()[1])
      #for line in err_lines:
      #    if "Command exited with non-zero" in line:
      #        CC2_KLEE_RESULT = ERROR
    except TimeoutExpired:
        proc.kill()
        #out, err = proc.communicate()
        CC2_KLEE_RESULT = "timeout"
        CC2_KLEE_TIME   = TIMEOUT

    try: 
      #TODO: WARNING - STATIC PATH ARGUMENT
      args = shlex.split("/usr/bin/time -p python3 ../../CLEVER+/CC2/merger/parser.py --old %s \
                --new %s --client %s --lib %s --unwind %d --BMC-incremental=True" 
                % (old_c_filename, new_c_filename, c_client, c_lib, UNWINDS))
      proc = subprocess.Popen(args, stdout=PIPE, stderr=PIPE)
      out, err = proc.communicate(timeout=TIMEOUT)
      out_lines = out.decode('utf8').split('\n')
      err_lines = err.decode('utf8').split('\n')
      for line in out_lines:
          if "Grow out of context, CEX" in line:
              CC2_CBMC_RESULT = NEQ
          elif "have been checked, CSE" in line:
              CC2_CBMC_RESULT = EQ
          elif "Solver decision Time:" in line:
              CC2_CBMC_SOLVE_TIME = float(line.lstrip("Solver decision Time: ").rstrip())
      #for line in err_lines:
      #    if "Command exited with non-zero" in line:
      #        CC2_CBMC_RESULT = ERROR
      if "real " in err_lines[-4]: #more robust?
          CC2_CBMC_TIME = float(err_lines[-4].split()[1])
    except TimeoutExpired:
        proc.kill()
        #out, err = proc.communicate()
        CC2_CBMC_RESULT = "timeout"
        CC2_CBMC_TIME = TIMEOUT"""

    try:    
      #TODO: WARNING - STATIC PATH ARGUMENT
      args = shlex.split("CLEVERC --old %s \
                --new %s --client %s --lib %s" % 
                            (old_c_filename, new_c_filename, c_client, c_lib))
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
              KLEECLEVER_TIME = float(line.lstrip("time : ").rstrip())
      #for line in err_lines:
      #    if "Command exited with non-zero" in line:
      #        KLEECLEVER_RESULT = ERROR
      #import pdb; pdb.set_trace()
    except TimeoutExpired:
        proc.kill()
        args = shlex.split("./kill_procs.sh") 
        kill = subprocess.Popen(args, stdout=PIPE, stderr=PIPE, shell=True)
        out, err = kill.communicate(timeout=TIMEOUT)
        KLEECLEVER_RESULT = "timeout"
        KLEECLEVER_TIME = TIMEOUT

    """try:    
      #TODO: WARNING - STATIC PATH ARGUMENT
      args = shlex.split("CLEVER %s %s --client %s --library %s int int" % 
                            (old_py_filename, new_py_filename, py_client, py_lib))
      proc = subprocess.Popen(args, stdout=PIPE, stderr=PIPE)
      out, err = proc.communicate(timeout=TIMEOUT)
      out_lines = out.decode('utf8').split('\n')
      for line in out_lines:
          if "Not CSE" in line:
              CLEVER_RESULT = NEQ
          elif "CSE Proven" in line:
              CLEVER_RESULT = EQ
          elif "Execution time:" in line:
              CLEVER_TIME = float(line.lstrip("Execution time: ").rstrip(" seconds"))
      for line in err_lines:
          if "Command exited with non-zero" in line:
              CLEVER_RESULT = ERROR
      #import pdb; pdb.set_trace()
    except TimeoutExpired:
        proc.kill()
        #out, err = proc.communicate()
        CLEVER_RESULT = "timeout"
        CLEVER_TIME = TIMEOUT"""

    print("%-35s CC2-Hybrid: %-8s ,%-8.4f (Solve) ,,%-7.3f\tCC2-Concurrent: %-8s ,%-8.4f (Solve) ,,%-7.3f\tKleeCLEVER: %-8s ,%-8.4f" % (dirpath, CC2_RESULT, CC2_TIME, CC2_SOLVE_TIME, CC2_CONC_RESULT, CC2_CONC_TIME, CC2_CONC_SOLVE_TIME, KLEECLEVER_RESULT, KLEECLEVER_TIME))    
    with open("timing_calls0.csv", 'a') as f:
        f.write("%-20s: %s,%-8.4f ; %s,%-8.4f ; %s,%-8.4f\n" %(dirpath, CC2_RESULT, CC2_TIME, CC2_CONC_RESULT, CC2_CONC_TIME, KLEECLEVER_RESULT, KLEECLEVER_TIME))
    if CC2_RESULT != KLEECLEVER_RESULT and CC2_RESULT != "timeout" and KLEECLEVER_RESULT != "timeout":
        print("Disagreement error: %s" % dirpath)
    
    """print("%-20s CC2-SEA: %-8s ,%-8.4f (Solve) ,,%-7.3f\tCC2-Hybrid: %-8s ,%-8.4f (Solve) ,,%-7.3f\tCC2-Concurrent: %-8s ,%-8.4f (Solve) ,,%-7.3f\tKleeCLEVER: %-8s ,%-8.4f" % (dirpath, CC2_SEA_RESULT, CC2_SEA_TIME, CC2_SEA_SOLVE_TIME, CC2_RESULT, CC2_TIME, CC2_SOLVE_TIME, CC2_CONC_RESULT, CC2_CONC_TIME, CC2_CONC_SOLVE_TIME, KLEECLEVER_RESULT, KLEECLEVER_TIME))
    with open("timing2.csv", 'a') as f:
        f.write("%-20s: %s,%-8.4f, %s,%-8.4f, %s,%-8.4f, %s,%-8.4f\n" %(dirpath, CC2_RESULT, CC2_TIME, CC2_SEA_RESULT, CC2_SEA_TIME, CC2_CONC_RESULT, CC2_CONC_TIME, KLEECLEVER_RESULT, KLEECLEVER_TIME))
    if CC2_RESULT != KLEECLEVER_RESULT and CC2_RESULT != "timeout" and KLEECLEVER_RESULT != "timeout" or CC2_RESULT != CC2_SEA_RESULT and CC2_SEA_RESULT != "timeout":
        print("Disagreement error: %s" % dirpath)"""
    continue
    """if EQLoopMult:
        EQLoopMultMap[loopnum] = (CC2_TIME, CC2_CBMC_TIME, CC2_KLEE_TIME, KLEECLEVER_TIME)
    if EQLoopUnreach:
        EQLoopUnreachMap[loopnum] = (CC2_TIME, CC2_CBMC_TIME, CC2_KLEE_TIME, KLEECLEVER_TIME)
    if NEQLoopMult:
        NEQLoopMultMap[loopnum] = (CC2_TIME, CC2_CBMC_TIME, CC2_KLEE_TIME, KLEECLEVER_TIME)
    if NEQLoopUnreach:    
        NEQLoopUnreachMap[loopnum] = (CC2_TIME, CC2_CBMC_TIME, CC2_KLEE_TIME, KLEECLEVER_TIME)"""
    #if (CC2_RESULT != CLEVER_RESULT):
    #    continue

    TT_CC2_SEA = 0
    TT_CC2_CBMC = 0
    TT_CLEVER = 0
    for i in range(REPEATS):
        try:    
          #TODO: WARNING - STATIC PATH ARGUMENT
          args = shlex.split("time -p python3 ../../CC2/merger/parser.py --old %s \
                      --new %s --client %s --lib %s --unwind %d --engine %s" 
                     % (old_c_filename, new_c_filename, c_client, c_lib, UNWINDS, "SEAHORN"))
          proc = subprocess.Popen(args, stdout=PIPE, stderr=PIPE)
          out, err = proc.communicate(timeout=TIMEOUT)
          out_lines = out.decode('utf8').split('\n')
          err_lines = err.decode('utf8').split('\n')
          for line in out_lines:
              if "Grow out of context, CEX" in line:
                  CC2_SEA_RESULT = NEQ
              elif "have been checked, CSE" in line:
                  CC2_SEA_RESULT = EQ
          if "real " in err_lines[-4]: #more robust?
              CC2_SEA_TIME = float(err_lines[-4].split()[1])
              TT_CC2_SEA = TT_CC2_SEA + CC2_SEA_TIME
        except TimeoutExpired:
            proc.kill()
            #out, err = proc.communicate()
            CC2_SEA_RESULT = TIMEOUT
            TT_CC2_SEA = TT_CC2_SEA + TIMEOUT
            print("CC2-SEA Timeout")

        try: 
          #TODO: WARNING - STATIC PATH ARGUMENT
          args = shlex.split("/usr/bin/time -p python3 ../../CC2/merger/parser.py --old %s \
                    --new %s --client %s --lib %s --unwind %d --BMC-incremental=True" 
                    % (old_c_filename, new_c_filename, c_client, c_lib, UNWINDS))
          proc = subprocess.Popen(args, stdout=PIPE, stderr=PIPE)
          out, err = proc.communicate(timeout=TIMEOUT)
          out_lines = out.decode('utf8').split('\n')
          err_lines = err.decode('utf8').split('\n')
          for line in out_lines:
              if "Grow out of context, CEX" in line:
                  CC2_CBMC_RESULT = NEQ
              elif "have been checked, CSE" in line:
                  CC2_CBMC_RESULT = EQ
          if "real " in err_lines[-4]: #more robust?
              CC2_CBMC_TIME = float(err_lines[-4].split()[1])
              TT_CC2_CBMC = TT_CC2_CBMC + CC2_CBMC_TIME
        except TimeoutExpired:
            proc.kill()
            #out, err = proc.communicate()
            CC2_CBMC_RESULT = "timeout"
            TT_CC2_CBMC = TT_CC2_CBMC + TIMEOUT
            print("CC2-CBMC Timeout")


        """try:    
          #TODO: WARNING - STATIC PATH ARGUMENT
          args = shlex.split("CLEVER %s %s --client %s --library %s int int" % 
                                (old_py_filename, new_py_filename, py_client, py_lib))
          proc = subprocess.Popen(args, stdout=PIPE, stderr=PIPE)
          out, err = proc.communicate(timeout=TIMEOUT)
          out_lines = out.decode('utf8').split('\n')
          for line in out_lines:
              if "Not CSE Through Exploration!" in line:
                  CLEVER_RESULT = NEQ
              elif "CSE Proven" in line:
                  CLEVER_RESULT = EQ
              elif "Execution time:" in line:
                  CLEVER_TIME = float(line.lstrip("Execution time: ").rstrip(" seconds"))
                  TT_CLEVER = TT_CLEVER + CLEVER_TIME
        except TimeoutExpired:
            proc.kill()
            out, err = proc.communicate()
            CLEVER_RESULT = TIMEOUT
            TT_CLEVER = TT_CLEVER + TIMEOUT
            print("CLEVER Timeout")"""
    #print("Avg Time(%d):\t CC2: %f\t PyCLEVER: %f" % (REPEATS, TT_CC2/REPEATS, TT_CLEVER/REPEATS))
    print("Avg Time(%d):\t CC2-SEA: %f\t CC2-CBMC: %f" % (REPEATS, TT_CC2_SEA/REPEATS, TT_CC2_CBMC/REPEATS))


