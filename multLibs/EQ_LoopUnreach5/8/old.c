int foo(int a, int b);
int clientmain(int x, int x_copy1, int x_copy2, int x_copy3, int x_copy4, int x_copy5, int x_copy6, int x_copy7)
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

  int ret_copy6 = 0;
  if ((x_copy6 >= 5) && (x_copy6 < 7))
    ret_copy6 = foo(x_copy6, 5);

  int ret_copy7 = 0;
  if ((x_copy7 >= 5) && (x_copy7 < 7))
    ret_copy7 = foo(x_copy7, 5);

  return ((((((ret + ret_copy1) + ret_copy2) + ret_copy3) + ret_copy4) + ret_copy5) + ret_copy6) + ret_copy7;
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

