int foo(int a, int b);
int clientmain(void, int x_copy1)
{
  foo(5, 900);
  return foo(5, 900) + foo(2, 2);
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= b; ++i)
    c += a;

  return c;
}

