int foo(int a, int b);
int clientmain(int x, int x_copy1)
{
  foo(2, 2);
  int ret_copy1;
  if (x_copy1 > 0)
  {
    ret_copy1 = -foo(-x_copy1, -x_copy1);
  }
  else
  {
    ret_copy1 = foo(x_copy1, x_copy1);
  }

  return foo(2, 2) + ret_copy1;
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

