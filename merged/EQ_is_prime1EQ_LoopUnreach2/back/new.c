int foo(int a, int b);
int client(unsigned int x, int x_copy1)
{
  foo(x, 0);
  return foo(x, 0) + foo(2, 2);
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

