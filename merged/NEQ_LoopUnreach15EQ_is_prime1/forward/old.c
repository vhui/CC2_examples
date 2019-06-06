int foo(int a, int b);
int clientmain(int x, unsigned int x_copy1)
{
  int ret = 0;
  if ((x >= 13) && (x < 16))
    ret = foo(x, 15);

  ret;
  return ret + foo(x_copy1, 0);
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

