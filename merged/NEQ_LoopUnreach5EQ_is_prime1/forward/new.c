int foo(int a, int b);
int clientmain(int x, unsigned int x_copy1)
{
  int ret = 0;
  if ((x >= 5) && (x < 7))
    ret = foo(x, 5);

  ret;
  return ret + foo(x_copy1, 0);
}

int foo(int a, int b)
{
  int c = 0;
  if (a < 0)
  {
    for (int i = 1; i <= a; ++i)
      c += b;

  }

  return c;
}

