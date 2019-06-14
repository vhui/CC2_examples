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
  int c = 1;
  if (a < 0)
  {
    for (int i = 1; i <= b; ++i)
      c += a;

  }

  return c;
}

