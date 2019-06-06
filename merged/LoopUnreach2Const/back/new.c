int foo(int a, int b);
int clientmain(int x, void)
{
  foo(2, 2);
  return foo(2, 2) + foo(5, 900);
}

int foo(int a, int b)
{
  const int d = 3;
  int c = b + a;
  return c + d;
}

