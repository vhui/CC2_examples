int foo(int a, int b);
int clientmain(int x, int x_copy1)
{
  int ret = 0;
  if ((x >= 9) && (x < 12))
    ret = foo(x, 10);

  ret;
  int ret_copy1 = 0;
  if ((x_copy1 >= 5) && (x_copy1 < 7))
    ret_copy1 = foo(x_copy1, 5);

  return ret + ret_copy1;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= a; ++i)
    c += b;

  return c;
}

