int foo(int a, int b);
int clientmain(int x, int x_copy1, int x_copy2, int x_copy3, int x_copy4, int x_copy5, int x_copy6, int x_copy7, int x_copy8, int x_copy9, int x_copy10, int x_copy11, int x_copy12, int x_copy13, int x_copy14)
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

  int ret_copy3 = 0;
  if ((x_copy3 >= 13) && (x_copy3 < 16))
    ret_copy3 = foo(x_copy3, 15);

  int ret_copy4 = 0;
  if ((x_copy4 >= 13) && (x_copy4 < 16))
    ret_copy4 = foo(x_copy4, 15);

  int ret_copy5 = 0;
  if ((x_copy5 >= 13) && (x_copy5 < 16))
    ret_copy5 = foo(x_copy5, 15);

  int ret_copy6 = 0;
  if ((x_copy6 >= 13) && (x_copy6 < 16))
    ret_copy6 = foo(x_copy6, 15);

  int ret_copy7 = 0;
  if ((x_copy7 >= 13) && (x_copy7 < 16))
    ret_copy7 = foo(x_copy7, 15);

  int ret_copy8 = 0;
  if ((x_copy8 >= 13) && (x_copy8 < 16))
    ret_copy8 = foo(x_copy8, 15);

  int ret_copy9 = 0;
  if ((x_copy9 >= 13) && (x_copy9 < 16))
    ret_copy9 = foo(x_copy9, 15);

  int ret_copy10 = 0;
  if ((x_copy10 >= 13) && (x_copy10 < 16))
    ret_copy10 = foo(x_copy10, 15);

  int ret_copy11 = 0;
  if ((x_copy11 >= 13) && (x_copy11 < 16))
    ret_copy11 = foo(x_copy11, 15);

  int ret_copy12 = 0;
  if ((x_copy12 >= 13) && (x_copy12 < 16))
    ret_copy12 = foo(x_copy12, 15);

  int ret_copy13 = 0;
  if ((x_copy13 >= 13) && (x_copy13 < 16))
    ret_copy13 = foo(x_copy13, 15);

  int ret_copy14 = 0;
  if ((x_copy14 >= 13) && (x_copy14 < 16))
    ret_copy14 = foo(x_copy14, 15);

  return (((((((((((((ret + ret_copy1) + ret_copy2) + ret_copy3) + ret_copy4) + ret_copy5) + ret_copy6) + ret_copy7) + ret_copy8) + ret_copy9) + ret_copy10) + ret_copy11) + ret_copy12) + ret_copy13) + ret_copy14;
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

