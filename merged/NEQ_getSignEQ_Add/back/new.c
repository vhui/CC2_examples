int foo(int a, int b);
int client(int x)
{
  foo(x, x);
  return foo(x, x) + foo(5, 900);
}

int foo(int a, int b)
{
  int c = b + a;
  return c;
}

