int foo(int a, int b);
int clientmain(int x)
{
  int ret = 0;
  if ((x >= 5) && (x < 7))
    ret = foo(x, 5);

  ret;
  return ret + foo(5, 900);
}

int foo(int a, int b)
{
  int c = b + a;
  return c;
}

