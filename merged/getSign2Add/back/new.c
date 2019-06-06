int foo(int a, int b);
int client(int x, void)
{
  int ret = x;
  if (x > 0)
  {
    ret = foo(x, x);
  }

  ret;
  return ret + foo(5, 900);
}

int foo(int a, int b)
{
  int c = b + a;
  return c;
}

