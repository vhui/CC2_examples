int foo(int a, int b);
int client(int x, void)
{
  int ret;
  if (x > 0)
  {
    ret = -foo(-x, -x);
  }
  else
  {
    ret = foo(x, x);
  }

  ret;
  return ret + foo(5, 900);
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

