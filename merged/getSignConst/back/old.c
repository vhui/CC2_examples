int foo(int a, int b);
int client(int x, void)
{
  foo(x, x);
  return foo(x, x) + foo(5, 900);
}

int foo(int a, int b)
{
  int c = a + b;
  return c + 3;
}

