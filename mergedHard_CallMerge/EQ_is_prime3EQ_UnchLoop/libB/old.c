int foo(int a, int b);
int client(int x)
{
  int ret;
  int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
  int done = 0;
  for (int i = 0; i < 8; i++)
  {
    if ((!done) && (x == primes[i]))
    {
      ret = 1;
      done = 1;
    }

  }

  if (!done)
    ret = foo(x, 1);

  return foo(5, 900);
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

