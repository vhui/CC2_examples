int foo(int a, int b);
int clientmain(int x, int x_copy1, int x_copy2)
{
  int ret = 0;
  if ((x >= 13) && (x < 16))
    ret = foo(x, 15);

  int ret_copy1 = 0;
  if ((x_copy1 >= 13) && (x_copy1 < 16))
    ret_copy1 = foo(x_copy1, 15);

  int ret_copy2 = 0;
  if ((x_copy2 >= 13) && (x_copy2 < 16))
    ret_copy2 = foo(x_copy2, 15);

  return (ret + ret_copy1) + ret_copy2;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= b; ++i)
    c += a;

  return c;
}

