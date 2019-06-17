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
        ret = 0;

    }

  }

  return ret;
}

int client(unsigned int x, unsigned int x_copy1, unsigned int x_copy2, unsigned int x_copy3)
{
  return ((lib(x, 0) + lib(x_copy1, 0)) + lib(x_copy2, 0)) + lib(x_copy3, 0);
}

int main()
{
  unsigned int x;
  return client(x);
}

