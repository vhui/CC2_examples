int foo(int a, int b);
int clientmain(int x, int x_copy1)
{
  int ret = 0;
  if ((x >= 9) && (x < 12))
    ret = foo(x, 10);

  ret;
  int ret_copy1;
  x_copy1 = (x_copy1 * 5) * 6;
  if (foo(x_copy1, x_copy1) == 0)
  {
    ret_copy1 = 1;
  }
  else
  {
    ret_copy1 = 0;
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

