int foo(int a, int b);
int clientmain(int x, int x_copy1, int x_copy2, int x_copy3)
{
  return ((foo(2, 2) + foo(2, 2)) + foo(2, 2)) + foo(2, 2);
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

