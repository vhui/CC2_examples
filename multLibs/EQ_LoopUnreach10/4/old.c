int foo(int a, int b);
int clientmain(int x, int x_copy1, int x_copy2, int x_copy3)
{
  int ret = 0;
  if ((x >= 9) && (x < 12))
    ret = foo(x, 10);

  int ret_copy1 = 0;
  if ((x_copy1 >= 9) && (x_copy1 < 12))
    ret_copy1 = foo(x_copy1, 10);

  int ret_copy2 = 0;
  if ((x_copy2 >= 9) && (x_copy2 < 12))
    ret_copy2 = foo(x_copy2, 10);

  int ret_copy3 = 0;
  if ((x_copy3 >= 9) && (x_copy3 < 12))
    ret_copy3 = foo(x_copy3, 10);

  return ((ret + ret_copy1) + ret_copy2) + ret_copy3;
}

int foo(int a, int b)
{
  int c = 0;
  if (a < 0)
  {
    for (int i = 1; i <= b; ++i)
      c += a;

  }

  return c;
}

