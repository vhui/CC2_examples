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
        return 0;

    }

  }

  return 1;
}

int client(int x, unsigned int x_copy1)
{
  int ret;
  if ((x < (-100)) || (x > 100))
  {
    ret = x;
  }
  else
  {
    if (x < 0)
    {
      ret = (-lib((-x) * 5, (-x) * 5)) / 5;
    }
    else
    {
      ret = (lib((x + 1) * 5, (x + 1) * 5) / 5) - 1;
    }

  }

  ret;
  return ret + lib(x_copy1, 0);
}

int main()
{
  unsigned int x;
  return client(x);
}

