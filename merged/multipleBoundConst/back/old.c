int foo(int a, int b);
int client(int x, void)
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
  return ret + foo(5, 900);
}

int foo(int a, int b)
{
  int c = a + b;
  return c + 3;
}

