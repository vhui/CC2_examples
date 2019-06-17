# define NUMPRIMES 8
/*static const unsigned int primes[8] = {
        2,     3,     5,     7,    11,    13,    17,    19};*/


int lib(unsigned int x, int b) {
  int ret = 1;
  unsigned int primes[8] = {
        2,     3,     5,     7,    11,    13,    17,    19};
  if (b == 0) {
    ret = 0;
  }
  else{
    for (int i = 0; i < NUMPRIMES; i++) {
      int mod = x % primes[i];
      if (mod == 0)
        ret = 0;
    }
  }
  return ret;
}

int client(unsigned int x){
  unsigned int primes[8] = {
        2,     3,     5,     7,    11,    13,    17,    19};
  for (int i = 0; i < NUMPRIMES; i++) {
    if (x == primes[i])
      return 1;
  }
  return lib(x,1);
}

int main() {
	unsigned int x;
	return client(x);
}
