int foo(int a, int b);
int clientmain(int x)
{
  int ret = 0;
  if ((x >= 18) && (x < 22))
    ret = foo(x, 20);

  int x_copy1 = ret;
  int ret_copy1 = 0;
  if ((x_copy1 >= 18) && (x_copy1 < 22))
    ret_copy1 = foo(x_copy1, 20);

  return ret_copy1;
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

