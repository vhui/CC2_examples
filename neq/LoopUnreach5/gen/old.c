int foo(int a, int b);
int clientmain(int x, int x_1)
{
  if ((x >= 5) && (x < 7))
    return foo(x, 5);

  0;
  if ((x_1 >= 5) && (x_1 < 7))
    return foo(x, 5);

  return 0;
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

