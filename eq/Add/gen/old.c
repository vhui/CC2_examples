int foo(int a, int b);
int clientmain(void, void)
{
  foo(5, 900);
  return foo(5, 900);
}

int foo(int a, int b)
{
  int c = a + b;
  return c;
}

