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
  unsigned int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
  int done = 0;
  for (int i = 0; i < 8; i++)
  {
    if ((!done) && (x == primes[i]))
    {
      ret = 1;
      done = 1;
    }

  }

  if (!done)
    ret = __inlineCall(lib(x, 1));

  int n_copy1 = ret;
  int i_copy1 = 0;
  int sum_copy1 = 0;
  while (i_copy1 <= n_copy1)
  {
    if (__inlineCall(lib(i_copy1, i_copy1)) == 0)
    {
      sum_copy1 += i_copy1;
    }

    i_copy1++;
  }

  return __inlineCall(lib(sum_copy1, sum_copy1)) == 0;
}

