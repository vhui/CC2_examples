int foo(int a, int b);
int clientmain(int x, int x_copy1, int x_copy2, int x_copy3, int x_copy4)
{
  return (((foo(2, 2) + foo(2, 2)) + foo(2, 2)) + foo(2, 2)) + foo(2, 2);
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
