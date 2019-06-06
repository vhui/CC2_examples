int foo(int a, int b);
int client(int x, int x_copy1)
{
  int ret;
  x = (x * 5) * 6;
  if (foo(x, x) == 0)
  {
    ret = 1;
  }
  else
  {
    ret = 0;
  }

  ret;
  int ret_copy1 = 0;
  if ((x_copy1 >= 13) && (x_copy1 < 16))
    ret_copy1 = foo(x_copy1, 15);

  return ret + ret_copy1;
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

