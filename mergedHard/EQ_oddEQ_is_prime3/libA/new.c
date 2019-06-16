int lib(int x)
{
  return (x + 1) % 2;
}

int client(int x, unsigned int x_copy1)
{
  int ret;
  if (lib(x) == 0)
  {
    ret = 1;
  }
  else
  {
    ret = 0;
  }

  const unsigned int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
  for (int i_copy1 = 0; i_copy1 < 8; i_copy1++)
  {
    if (x_copy1 == primes_copy1[i_copy1])
      return 1;

  }

  return ret + lib(x_copy1);
}

int main()
{
  int x;
  return client(x);
}

