#./bin/sh
kill $(ps aux | grep seahorn | awk '{print $2}')
kill $(ps aux | grep klee | awk '{print $2}')
kill $(ps aux | grep cbmc | awk '{print $2}')
kill $(ps aux | grep z3 | awk '{print $2}')
#kill $(ps aux | grep seahorn | awk '{print $2}')

