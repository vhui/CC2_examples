int foo(int a, int b);
int clientmain(int x, int x_copy1)
{
  int ret = 0;
  if ((x >= 13) && (x < 16))
    ret = foo(x, 15);

  ret;
  return ret + foo(2, 2);
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= a; ++i)
    c += b;

  return c;
}
