int foo(int a, int b);
int clientmain(int x_copy1)
{
  foo(5, 900);
  return foo(5, 900) + foo(2, 2);
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= a; ++i)
    c += b;

  return c;
}

