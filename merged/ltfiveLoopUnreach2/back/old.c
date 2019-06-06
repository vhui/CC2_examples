int foo(int a, int b);
int client(int x, int x_copy1)
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

  ret;
  return ret + foo(2, 2);
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

