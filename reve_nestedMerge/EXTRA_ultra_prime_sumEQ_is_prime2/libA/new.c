int client(int n)
{
  int INLINED_RET_0;
  int INLINED_RET_1;
  int i = 0;
  int sum = 0;
  while (i <= n)
  {
    unsigned int x_copy0 = i;
    int ret_copy0;
    if (x_copy0 < 19)
    {
      ret_copy0 = __inlineCall(lib(20, 1));
    }
    else
    {
      ret_copy0 = __inlineCall(lib(x_copy0, 1));
    }

    INLINED_RET_0 = ret_copy0;
    if (__inlineCall(INLINED_RET_0) == 0)
    {
      sum += i;
    }

    i++;
  }

  unsigned int x_copy1 = sum;
  int ret_copy1;
  if (x_copy1 < 19)
  {
    ret_copy1 = __inlineCall(lib(20, 1));
  }
  else
  {
    ret_copy1 = __inlineCall(lib(x_copy1, 1));
  }

  INLINED_RET_1 = ret_copy1;
  return __inlineCall(INLINED_RET_1) == 0;
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


