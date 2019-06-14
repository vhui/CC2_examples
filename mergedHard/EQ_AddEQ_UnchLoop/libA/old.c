int foo(int a, int b);
int clientmain()
{
  foo(5, 900);
  return foo(5, 900) + foo(5, 900);
}

int foo(int a, int b)
{
  int c = a + b;
  return c;
}

