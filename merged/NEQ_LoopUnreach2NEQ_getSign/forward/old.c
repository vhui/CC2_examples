int foo(int a, int b);
int clientmain(int x, int x_copy1)
{
  foo(2, 2);
  return foo(2, 2) + foo(x_copy1, x_copy1);
}

int foo(int a, int b)
{
  int c = 1;
  if (a < 0)
  {
    for (int i = 1; i <= b; ++i)
      c += a;

  }

  return c;
}

