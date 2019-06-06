int lib(int x)
{
  if (x < 5)
    return 5;
  else
    return x;

}

int client(int x, unsigned int x_copy1)
{
  int ret;
  if (x < 0)
  {
    ret = (-lib((-x) * 5)) / 5;
  }
  else
  {
    ret = (lib((x + 1) * 5) / 5) - 1;
  }

  ret;
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

