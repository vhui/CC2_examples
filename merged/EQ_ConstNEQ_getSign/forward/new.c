int foo(int a, int b);
int clientmain(void, int x_copy1)
{
  foo(5, 900);
  return foo(5, 900) + foo(x_copy1, x_copy1);
}

int foo(int a, int b)
{
  const int d = 3;
  int c = b + a;
  return c + d;
}

