int foo(int a, int b);
int clientmain(unsigned int x_copy1)
{
  foo(5, 900);
  for (int i_copy1 = 0; i_copy1 < 8; i_copy1++)
  {
    if (x_copy1 == primes_copy1[i_copy1])
      return 1;

  }

  return foo(5, 900) + foo(x_copy1, 1);
}

int foo(int a, int b)
{
  const int d = 3;
  int c = b + a;
  return c + d;
}

