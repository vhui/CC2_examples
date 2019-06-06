int foo(int a, int b);
int client(int x, int x_copy1)
{
  int ret = x;
  if (x > 0)
  {
    ret = foo(x, x);
  }

  ret;
  return ret + foo(2, 2);
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

