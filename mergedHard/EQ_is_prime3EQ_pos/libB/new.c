int lib(int x)
{
  if (x < 0)
  {
    return -x;
  }
  else
  {
    return x;
  }

}

int client(unsigned int x, int x_copy1)
{
  unsigned int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
  for (int i = 0; i < 8; i++)
  {
    if (x == primes[i])
      return 1;

  }

  int ret_copy1;
  if (x_copy1 > 0)
  {
    ret_copy1 = -lib(-x_copy1);
  }
  else
  {
    ret_copy1 = lib(x_copy1);
  }

  return lib(x) + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

