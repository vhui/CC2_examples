int foo(int a, int b);
int clientmain(int x)
{
  int ret = 0;
  if ((x >= 13) && (x < 16))
    ret = foo(x, 15);

  ret;
  return ret + foo(5, 900);
}

int foo(int a, int b)
{
  int c = 0;
  if (a < 0)
  {
    for (int i = 1; i <= b; ++i)
      c += a;

  }

  return c;
}

