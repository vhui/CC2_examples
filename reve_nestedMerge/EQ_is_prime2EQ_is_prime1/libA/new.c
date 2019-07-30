extern int __inlineCall(int);

int client(unsigned int x)
{
  int INLINED_RET_1;
  int INLINED_RET_0;
  int ret;
  if (x < 19)
  {
    unsigned int x_copy0 = 20;
    INLINED_RET_0 = __inlineCall(lib(x_copy0, 0));
    ret = INLINED_RET_0;
  }
  else
  {
    unsigned int x_copy1 = x;
    INLINED_RET_1 = __inlineCall(lib(x_copy1, 0));
    ret = INLINED_RET_1;
  }

  return ret;
}

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


