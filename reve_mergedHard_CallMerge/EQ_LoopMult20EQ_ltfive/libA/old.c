extern int __inlineCall(int);
int foo(int a, int b);
int clientmain(int x)
{
  int ret = 0;
  if ((x >= 18) && (x < 22))
    ret = __inlineCall(foo(x, 20));

  int x_copy1 = ret;
  int ret_copy1;
  if (x_copy1 < 0)
  {
    ret_copy1 = (-__inlineCall(foo((-x_copy1) * 5, (-x_copy1) * 5))) / 5;
  }
  else
  {
    ret_copy1 = (__inlineCall(foo((x_copy1 + 1) * 5, (x_copy1 + 1) * 5)) / 5) - 1;
  }

  return ret_copy1;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= b; ++i)
    c += a;

  return c;
}

