extern int __inlineCall(int);
int foo(int a, int b);
int clientmain(int x)
{
  int ret = 0;
  if ((x >= 18) && (x < 22))
    ret = __inlineCall(foo(x, 20));

  return __inlineCall(foo(5, 900));
}

int foo(int a, int b)
{
  int c = b + a;
  return c;
}

