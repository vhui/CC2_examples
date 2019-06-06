int foo(int a, int b);
int clientmain(void, int x_copy1)
{
  foo(5, 900);
  return foo(5, 900) + foo(2, 2);
}

int foo(int a, int b)
{
  int c = b + a;
  return c;
}

