int foo(int a, int b);
int clientmain(int x)
{
  int ret = 0;
  if ((x >= 9) && (x < 12))
    ret = foo(x, 10);

  ret;
  return ret + foo(5, 900);
}

int foo(int a, int b)
{
  int c = a + b;
  return c;
}

