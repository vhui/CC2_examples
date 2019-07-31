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
        ret = 0;
        done = 1;
      }

    }

  }

  return ret;
}

int client(int x)
{
  int ret;
  if (x > 0)
  {
    ret = -lib(-x, -x);
  }
  else
  {
    ret = lib(x, x);
  }

  int x_copy1 = ret;
  return lib(x_copy1, 0);
}

