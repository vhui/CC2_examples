int foo(int a, int b);
int clientmain(int x, int x_1)
{
  if ((x >= 18) && (x < 22))
    return foo(x, 20);

  0;
  if ((x_1 >= 18) && (x_1 < 22))
    return foo(x, 20);

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

