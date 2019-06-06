int foo(int a, int b);
int clientmain(int x, unsigned int x_copy1)
{
  int ret = 0;
  if ((x >= 13) && (x < 16))
    ret = foo(x, 15);

  ret;
  for (int i_copy1 = 0; i_copy1 < 8; i_copy1++)
  {
    if (x_copy1 == primes_copy1[i_copy1])
      return 1;

  }

  return ret + foo(x_copy1, 1);
}

int foo(int a, int b)
{
  int c = 0;
  if (a < 0)
  {
    for (int i = 1; i <= a; ++i)
      c += b;

  }

  return c;
}

