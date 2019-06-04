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
  int c = 0;
  for (int i = 1; i <= a; ++i)
    c += b;

  return c;
}

