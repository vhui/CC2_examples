int foo(int a, int b);
int client(int x, void)
{
  foo(x, x);
  return foo(x, x) + foo(5, 900);
}

int foo(int a, int b)
{
  int c = 1;
  for (int i = 0; i < a; ++i)
  {
    c = c + b;
  }

  return c;
}

