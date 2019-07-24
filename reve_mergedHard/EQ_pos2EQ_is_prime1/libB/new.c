extern int __inlineCall(int);
int lib(unsigned int x, int b)
{
  int ret = 1;
  unsigned int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
  if (b == 0)
  {
    ret = 0;
  }
  else
  {
    int done = 0;
    for (int i = 0; i < 8; i++)
    {
      int mod = x % primes[i];
      if ((!done) && (mod == 0))
      {
        ret = x == primes[i];
        done = 1;
      }

    }

  }

  return ret;
}

int client(int x, unsigned int x_copy1)
{
  int ret;
  if (x > 0)
  {
    ret = -__inlineCall(lib(-x, -x));
  }
  else
  {
    ret = __inlineCall(lib(x, x));
  }

  return ret + __inlineCall(lib(x_copy1, 0));
}
