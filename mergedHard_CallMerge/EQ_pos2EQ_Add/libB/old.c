int foo(int a, int b);
int client(int x)
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

  return foo(5, 900);
}

int foo(int a, int b)
{
  int c = a + b;
  return c;
}

