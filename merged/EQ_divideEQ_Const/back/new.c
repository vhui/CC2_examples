int foo(int a, int b);
int client(int c, int d)
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
  const int d = 3;
  int c = b + a;
  return c + d;
}

