int lib(int x)
{
  if (x > 10)
    return 11;
  else
    return x;

}

int client(unsigned int x, int x_copy1)
{
  for (int i = 0; i < 8; i++)
  {
    if (x == primes[i])
      return 1;

  }

  lib(x);
  int ret_copy1;
  if (x_copy1 > lib(x_copy1))
    ret_copy1 = x_copy1;
  else
    ret_copy1 = lib(x_copy1);

  return lib(x) + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

