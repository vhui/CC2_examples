int foo(int a, int b);
int client(unsigned int x)
{
  int ret;
  if (x < 19)
  {
    ret = foo(20, 1);
  }
  else
  {
    ret = foo(x, 1);
  }

  return foo(5, 900);
}

int foo(int a, int b)
{
  int c = a + b;
  return c;
}

