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

int client(int x, unsigned int x_copy1)
{
  int ret;
  if ((x < (-100)) || (x > 100))
  {
    ret = x;
  }
  else
  {
    if (x > lib(x, x))
      ret = x;
    else
      ret = lib(x, x);

  }

  int ret_copy1;
  if (x_copy1 < 19)
  {
    ret_copy1 = lib(20, 1);
  }
  else
  {
    ret_copy1 = lib(x_copy1, 1);
  }

  return ret + ret_copy1;
}

int main()
{
  unsigned int x = 2;
  return client(x);
}

