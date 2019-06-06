int lib(int x)
{
  if (x > 10)
    return 12;
  else
    return x + 1;

}

int client(int x, unsigned int x_copy1)
{
  int ret;
  if (x > lib(x))
    ret = x;
  else
    ret = lib(x);

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

