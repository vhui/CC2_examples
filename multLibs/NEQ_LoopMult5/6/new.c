int foo(int a, int b);
int clientmain(int x, int x_copy1, int x_copy2, int x_copy3, int x_copy4, int x_copy5)
{
  int ret = 0;
  if ((x >= 5) && (x < 7))
    ret = foo(x, 5);

  int ret_copy1 = 0;
  if ((x_copy1 >= 5) && (x_copy1 < 7))
    ret_copy1 = foo(x_copy1, 5);

  int ret_copy2 = 0;
  if ((x_copy2 >= 5) && (x_copy2 < 7))
    ret_copy2 = foo(x_copy2, 5);

  int ret_copy3 = 0;
  if ((x_copy3 >= 5) && (x_copy3 < 7))
    ret_copy3 = foo(x_copy3, 5);

  int ret_copy4 = 0;
  if ((x_copy4 >= 5) && (x_copy4 < 7))
    ret_copy4 = foo(x_copy4, 5);

  int ret_copy5 = 0;
  if ((x_copy5 >= 5) && (x_copy5 < 7))
    ret_copy5 = foo(x_copy5, 5);

  return ((((ret + ret_copy1) + ret_copy2) + ret_copy3) + ret_copy4) + ret_copy5;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= a; ++i)
    c += b;

  return c;
}

