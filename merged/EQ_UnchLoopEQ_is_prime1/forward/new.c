int foo(int a, int b);
int clientmain(void, unsigned int x_copy1)
{
  foo(5, 900);
  return foo(5, 900) + foo(x_copy1, 0);
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 0; i < a; ++i)
  {
    c = c + b;
  }

  return c + 1;
}

