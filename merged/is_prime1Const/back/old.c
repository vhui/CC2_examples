int foo(int a, int b);
int client(unsigned int x, void)
{
  foo(x, 0);
  return foo(x, 0) + foo(5, 900);
}

int foo(int a, int b)
{
  int c = a + b;
  return c + 3;
}

