int client(int x)
{
  int INLINED_RET_1;
  int INLINED_RET_0;
  int ret;
  if (x < 0)
  {
    unsigned int x_copy0 = (-x) * 5;
    int ret_copy0;
    if (x_copy0 < 19)
    {
      ret_copy0 = lib(20, 1);
    }
    else
    {
      ret_copy0 = lib(x_copy0, 1);
    }

    INLINED_RET_0 = ret_copy0;
    ret = (-INLINED_RET_0) / 5;
  }
  else
  {
    unsigned int x_copy1 = (x + 1) * 5;
    int ret_copy1;
    if (x_copy1 < 19)
    {
      ret_copy1 = lib(20, 1);
    }
    else
    {
      ret_copy1 = lib(x_copy1, 1);
    }

    INLINED_RET_1 = ret_copy1;
    ret = (INLINED_RET_1 / 5) - 1;
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
        ret = 0;
        done = 1;
      }

    }

  }

  return ret;
}

