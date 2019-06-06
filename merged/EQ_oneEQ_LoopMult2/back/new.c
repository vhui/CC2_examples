int foo(int a, int b);
int client(int x, int x_copy1)
{
  int ret;
  if (x > foo(x, x))
    ret = x;
  else
    ret = foo(x, x);

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

