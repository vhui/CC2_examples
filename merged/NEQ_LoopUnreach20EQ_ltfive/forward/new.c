int foo(int a, int b);
int clientmain(int x, int x_copy1)
{
  int ret = 0;
  if ((x >= 18) && (x < 22))
    ret = foo(x, 20);

  ret;
  int ret_copy1;
  if (x_copy1 < 0)
  {
    ret_copy1 = (-foo((-x_copy1) * 5, (-x_copy1) * 5)) / 5;
  }
  else
  {
    ret_copy1 = (foo((x_copy1 + 1) * 5, (x_copy1 + 1) * 5) / 5) - 1;
  }

  return ret + ret_copy1;
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

