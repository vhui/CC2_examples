int foo(int a, int b);
int client(int x, int x_copy1)
{
  foo(x, x);
  return foo(x, x) + foo(2, 2);
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= a; ++i)
    c += b;

  return c;
}

