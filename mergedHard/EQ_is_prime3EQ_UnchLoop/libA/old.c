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
        return 0;

    }

  }

  return 1;
}

int client(unsigned int x)
{
  unsigned int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
  for (int i = 0; i < 8; i++)
  {
    if (x == primes[i])
      return 1;

  }

  return lib(x, 1) + lib(5, 900);
}

int main()
{
  unsigned int x;
  return client(x);
}

