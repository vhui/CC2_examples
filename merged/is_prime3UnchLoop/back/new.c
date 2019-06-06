int foo(int a, int b);
int client(unsigned int x, void)
{
  for (int i = 0; i < 8; i++)
  {
    if (x == primes[i])
      return 1;

  }

  foo(x, 1);
  return foo(x, 1) + foo(5, 900);
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 0; i < a; ++i)
  {
    c = c + b;
  }

  return c + 1;
}

