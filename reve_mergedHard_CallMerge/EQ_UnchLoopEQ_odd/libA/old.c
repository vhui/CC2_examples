extern int __inlineCall(int);
int foo(int a, int b);
int clientmain()
{
  int x_copy1 = __inlineCall(foo(5, 900));
  int ret_copy1;
  if (__inlineCall(foo(x_copy1, x_copy1)) == 0)
  {
    ret_copy1 = 1;
  }
  else
  {
    ret_copy1 = 0;
  }

  return ret_copy1;
}

int foo(int a, int b)
{
  int c = 1;
  for (int i = 0; i < a; ++i)
  {
    c = c + b;
  }

  return c;
}

