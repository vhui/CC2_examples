int foo(int a, int b);
int client(int x)
{
  int ret;
  if (foo(x, x) == 0)
  {
    ret = 1;
  }
  else
  {
    ret = 0;
  }

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

