int foo(int a, int b);
int clientmain(void, void)
{
  foo(5, 900);
  return foo(5, 900);
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

