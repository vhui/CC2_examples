int foo(int a, int b);
int client(unsigned int x)
{
  foo(x, 0);
  return foo(x, 0) + foo(5, 900);
}

int foo(int a, int b)
{
  const int d = 3;
  int c = b + a;
  return c + d;
}

