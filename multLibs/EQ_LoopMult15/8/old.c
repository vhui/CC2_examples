int foo(int a, int b);
int clientmain(int x, int x_copy1, int x_copy2, int x_copy3, int x_copy4, int x_copy5, int x_copy6, int x_copy7)
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

  return ((((((ret + ret_copy1) + ret_copy2) + ret_copy3) + ret_copy4) + ret_copy5) + ret_copy6) + ret_copy7;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= b; ++i)
    c += a;

  return c;
}

