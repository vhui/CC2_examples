int foo(int a, int b);
int client(int x, int x_copy1)
{
  int ret;
  if ((x < (-100)) || (x > 100))
  {
    ret = x;
  }
  else
  {
    x = (x * 5) * 6;
    if (foo(x, x) == 0)
    {
      ret = 1;
    }
    else
    {
      ret = 0;
    }

  }

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

