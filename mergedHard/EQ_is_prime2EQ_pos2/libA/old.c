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
    for (int i = 0; i < 8; i++)
    {
      int mod = x % primes[i];
      if (mod == 0)
        ret = x == primes[i];

    }

  }

  return ret;
}

int client(unsigned int x, int x_copy1)
{
  int ret;
  if (x < 19)
  {
    ret = lib(20, 1);
  }
  else
  {
    ret = lib(x, 1);
  }

  int ret_copy1;
  if (x_copy1 > 0)
  {
    ret_copy1 = -lib(-x_copy1, -x_copy1);
  }
  else
  {
    ret_copy1 = lib(x_copy1, x_copy1);
  }

  return ret + ret_copy1;
}

int main()
{
  unsigned int x = 2;
  return client(x);
}

