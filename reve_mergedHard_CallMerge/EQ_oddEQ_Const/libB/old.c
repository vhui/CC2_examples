extern int __inlineCall(int);
int foo(int a, int b);
int client(int x)
{
  int ret;
  if (__inlineCall(foo(x, x)) == 0)
  {
    ret = 1;
  }
  else
  {
    ret = 0;
  }

  return __inlineCall(foo(5, 900));
}

int foo(int a, int b)
{
  int c = a + b;
  return c + 3;
}
