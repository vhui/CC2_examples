int foo(int a, int b);
int client(int x, void)
{
  int ret;
  if ((x < (-100)) || (x > 100))
  {
    ret = x;
  }
  else
  {
    if (x > foo(x, x))
      ret = x;
    else
      ret = foo(x, x);

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

