int foo(int a, int b);
int clientmain(int x, unsigned int x_copy1)
{
  int ret = 0;
  if ((x >= 9) && (x < 12))
    ret = foo(x, 10);

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
    for (int i = 1; i <= b; ++i)
      c += a;

  }

  return c;
}

