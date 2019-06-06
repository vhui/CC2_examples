int lib(int x)
{
  if (x <= 0)
    return -1;
  else
    return 1;

}

int client(int x, unsigned int x_copy1)
{
  lib(x);
  for (int i_copy1 = 0; i_copy1 < 8; i_copy1++)
  {
    if (x_copy1 == primes_copy1[i_copy1])
      return 1;

  }

  return lib(x) + lib(x_copy1);
}

int main()
{
  int x;
  return client(x);
}

