extern int __inlineCall(int);
int foo(int a, int b);
int client(int x)
{
  int ret;
  if (x > 0)
  {
    ret = -__inlineCall(foo(-x, -x));
  }
  else
  {
    ret = __inlineCall(foo(x, x));
  }

  return __inlineCall(foo(5, 900));
}

int foo(int a, int b)
{
  int c = b + a;
  return c;
}
