int foo(int a, int b);
int clientmain(void, int x_copy1)
{
  foo(5, 900);
  return foo(5, 900) + foo(x_copy1, x_copy1);
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

