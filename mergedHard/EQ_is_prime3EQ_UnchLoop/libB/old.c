int foo(int a, int b);
int client(unsigned int x)
{
  const unsigned int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
  for (int i = 0; i < 8; i++)
  {
    if (x == primes[i])
      return 1;

  }

  return foo(x, 1) + foo(5, 900);
}

int foo(int a, int b)
{
  int c = 1;
  for (int i = 0; i < a; ++i)
  {
    c = c + b;
  }

  return c;
}

