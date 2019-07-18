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

int client(int n)
{
  int i = 0;
  int sum = 0;
  while (i <= n)
  {
    if (lib(i, i) == 0)
    {
      sum += i;
    }

    i++;
  }

  unsigned int x_copy1 = lib(sum, sum) == 0;
  return lib(x_copy1, 0);
}
