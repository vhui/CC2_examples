int lib(unsigned int x, int b)
{
  const unsigned int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
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

int client(unsigned int x, int x_copy1)
{
  const unsigned int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
  for (int i = 0; i < 8; i++)
  {
    if (x == primes[i])
      return 1;

  }

  int ret_copy1;
  if (lib(x_copy1, x_copy1) == 0)
  {
    ret_copy1 = 1;
  }
  else
  {
    ret_copy1 = 0;
  }

  return lib(x, 1) + ret_copy1;
}

int main()
{
  unsigned int x;
  return client(x);
}

