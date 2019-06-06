int foo(int a, int b);
int client(int x, int x_copy1)
{
  int ret;
  if (x > foo(x, x))
    ret = x;
  else
    ret = foo(x, x);

  ret;
  int ret_copy1 = 0;
  if ((x_copy1 >= 9) && (x_copy1 < 12))
    ret_copy1 = foo(x_copy1, 10);

  return ret + ret_copy1;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= b; ++i)
    c += a;

  return c;
}

