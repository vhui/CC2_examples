int foo(int a, int b);
int clientmain(unsigned int x_copy1)
{
  foo(5, 900);
  return foo(5, 900) + foo(x_copy1, 0);
}

int foo(int a, int b)
{
  int c = a + b;
  return c;
}

