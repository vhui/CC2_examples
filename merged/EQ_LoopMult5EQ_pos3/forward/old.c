int foo(int a, int b);
int clientmain(int x, int x_copy1)
{
  int ret = 0;
  if ((x >= 5) && (x < 7))
    ret = foo(x, 5);

  ret;
  int ret_copy1 = -x_copy1;
  if (x_copy1 < 0)
  {
    ret_copy1 = foo(x_copy1, x_copy1);
  }

  return ret + ret_copy1;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= b; ++i)
    c += a;

  return c;
}

