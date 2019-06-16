int lib(unsigned int x, int b)
{
  unsigned int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
  if (b == 0)
  {
    return 0;
  }
  else
  {
    for (int i = 0; i < 8; i++)
    {
      int mod = x % primes[i];
      if (mod == 0)
        return x == primes[i];

    }

  }

  return 1;
}

int client(unsigned int x, int n_copy1)
{
  int i_copy1 = 0;
  int sum_copy1 = 0;
  while (i_copy1 <= n_copy1)
  {
    if (lib(i_copy1, i_copy1) == 0)
    {
      sum_copy1 += i_copy1;
    }

    i_copy1++;
  }

  return lib(x, 0) + sum_copy1;
}

int main()
{
  unsigned int x;
  return client(x);
}

