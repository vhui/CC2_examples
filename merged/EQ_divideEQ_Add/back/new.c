int foo(int a, int b);
int client(int c, int d, void)
{
  int ret;
  if (d == 0)
  {
    ret = 0;
  }
  else
  {
    ret = foo(c, d);
  }

  ret;
  return ret + foo(5, 900);
}

int foo(int a, int b)
{
  int c = b + a;
  return c;
}

