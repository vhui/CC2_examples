extern int __inlineCall(int);

int lib(int x, int b)
{
  int ret = 1;
  int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
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

int client(int x)
{
  int INLINED_RET_0;
  int ret;
  if ((x < (-100)) || (x > 100))
  {
    ret = x;
  }
  else
  {
    x = (x * 5) * 6;
    int x_copy0 = x;
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
    if (INLINED_RET_0 == 0)
    {
      ret = 1;
    }
    else
    {
      ret = 0;
    }

  }

  return ret;
}


