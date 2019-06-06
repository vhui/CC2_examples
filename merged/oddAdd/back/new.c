int foo(int a, int b);
int client(int x, void)
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

  ret;
  return ret + foo(5, 900);
}

int foo(int a, int b)
{
  int c = b + a;
  return c;
}

