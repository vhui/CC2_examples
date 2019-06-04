int foo(int a, int b);
int clientmain(int x, int x_1)
{
  if ((x >= 9) && (x < 12))
    return foo(x, 10);

  0;
  if ((x_1 >= 9) && (x_1 < 12))
    return foo(x, 10);

  return 0;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= b; ++i)
    c += a;

  return c;
}

