int foo(int a, int b);
int clientmain(int x, int x_copy1, int x_copy2, int x_copy3, int x_copy4, int x_copy5, int x_copy6, int x_copy7, int x_copy8, int x_copy9, int x_copy10, int x_copy11, int x_copy12, int x_copy13, int x_copy14)
{
  return (((((((((((((foo(2, 2) + foo(2, 2)) + foo(2, 2)) + foo(2, 2)) + foo(2, 2)) + foo(2, 2)) + foo(2, 2)) + foo(2, 2)) + foo(2, 2)) + foo(2, 2)) + foo(2, 2)) + foo(2, 2)) + foo(2, 2)) + foo(2, 2)) + foo(2, 2);
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

