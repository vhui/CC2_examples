int foo(int a, int b);
int client(int x, void)
{
  int ret;
  if (x > foo(x, x))
    ret = x;
  else
    ret = foo(x, x);

  ret;
  return ret + foo(5, 900);
}

int foo(int a, int b)
{
  int c = a + b;
  return c + 3;
}

