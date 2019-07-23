extern int __inlineCall(int);
int foo(int a, int b);
int client(unsigned int x)
{
  int ret;
  if (x < 19)
  {
    ret = __inlineCall(foo(20, 1));
  }
  else
  {
    ret = __inlineCall(foo(x, 1));
  }

  return __inlineCall(foo(5, 900));
}

int foo(int a, int b)
{
  int c = a + b;
  return c + 3;
}

