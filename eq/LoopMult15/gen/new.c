int foo(int a, int b);
int clientmain(int x, int x_1)
{
  if ((x >= 13) && (x < 16))
    return foo(x, 15);

  0;
  if ((x_1 >= 13) && (x_1 < 16))
    return foo(x, 15);

  return 0;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= a; ++i)
    c += b;

  return c;
}

