static const unsigned int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
int lib(unsigned int x, int b)
{
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

int client(int x, unsigned int x_copy1)
{
  int ret;
  if (x > lib(x, x))
    ret = x;
  else
    ret = lib(x, x);

  ret;
  for (int i_copy1 = 0; i_copy1 < 8; i_copy1++)
  {
    if (x_copy1 == primes_copy1[i_copy1])
      return 1;

  }

  return ret + lib(x_copy1, 1);
}

int main()
{
  unsigned int x;
  return client(x);
}

