int foo(int a, int b);
int client(int x)
{
  int ret;
  if (x < 0)
  {
    ret = (-foo((-x) * 5, (-x) * 5)) / 5;
  }
  else
  {
    ret = (foo((x + 1) * 5, (x + 1) * 5) / 5) - 1;
  }

  int x_copy1 = ret;
  int ret_copy1 = 0;
  if ((x_copy1 >= 18) && (x_copy1 < 22))
    ret_copy1 = foo(x_copy1, 20);

  return ret_copy1;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= a; ++i)
    c += b;

  return c;
}
