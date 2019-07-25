int foo(int a, int b);
int client(int x)
{
  int ret = -x;
  if (x < 0)
  {
    ret = foo(x, x);
  }

  return ret + foo(5, 900);
}

int foo(int a, int b)
{
  const int d = 3;
  int c = b + a;
  return c + d;
}

