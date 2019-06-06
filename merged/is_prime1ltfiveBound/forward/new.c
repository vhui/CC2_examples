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

int client(unsigned int x, int x_copy1)
{
  lib(x, 0);
  int ret_copy1;
  if ((x_copy1 < (-100)) || (x_copy1 > 100))
  {
    ret_copy1 = x_copy1;
  }
  else
  {
    if (x_copy1 < 0)
    {
      ret_copy1 = (-lib((-x_copy1) * 5, (-x_copy1) * 5)) / 5;
    }
    else
    {
      ret_copy1 = (lib((x_copy1 + 1) * 5, (x_copy1 + 1) * 5) / 5) - 1;
    }

  }

  return lib(x, 0) + ret_copy1;
}

int main()
{
  unsigned int x;
  return client(x);
}

