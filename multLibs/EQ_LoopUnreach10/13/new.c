int foo(int a, int b);
int clientmain(int x, int x_copy1, int x_copy2, int x_copy3, int x_copy4, int x_copy5, int x_copy6, int x_copy7, int x_copy8, int x_copy9, int x_copy10, int x_copy11, int x_copy12)
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

  int ret_copy4 = 0;
  if ((x_copy4 >= 9) && (x_copy4 < 12))
    ret_copy4 = foo(x_copy4, 10);

  int ret_copy5 = 0;
  if ((x_copy5 >= 9) && (x_copy5 < 12))
    ret_copy5 = foo(x_copy5, 10);

  int ret_copy6 = 0;
  if ((x_copy6 >= 9) && (x_copy6 < 12))
    ret_copy6 = foo(x_copy6, 10);

  int ret_copy7 = 0;
  if ((x_copy7 >= 9) && (x_copy7 < 12))
    ret_copy7 = foo(x_copy7, 10);

  int ret_copy8 = 0;
  if ((x_copy8 >= 9) && (x_copy8 < 12))
    ret_copy8 = foo(x_copy8, 10);

  int ret_copy9 = 0;
  if ((x_copy9 >= 9) && (x_copy9 < 12))
    ret_copy9 = foo(x_copy9, 10);

  int ret_copy10 = 0;
  if ((x_copy10 >= 9) && (x_copy10 < 12))
    ret_copy10 = foo(x_copy10, 10);

  int ret_copy11 = 0;
  if ((x_copy11 >= 9) && (x_copy11 < 12))
    ret_copy11 = foo(x_copy11, 10);

  int ret_copy12 = 0;
  if ((x_copy12 >= 9) && (x_copy12 < 12))
    ret_copy12 = foo(x_copy12, 10);

  return (((((((((((ret + ret_copy1) + ret_copy2) + ret_copy3) + ret_copy4) + ret_copy5) + ret_copy6) + ret_copy7) + ret_copy8) + ret_copy9) + ret_copy10) + ret_copy11) + ret_copy12;
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

