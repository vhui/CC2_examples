extern int __inlineCall(int);
int foo(int a, int b);
int clientmain(int x_copy1)
{
  int ret_copy1;
  if (x_copy1 < 19)
  {
    ret_copy1 = __inlineCall(foo(20, 1));
  }
  else
  {
    ret_copy1 = __inlineCall(foo(x_copy1, 1));
  }

  return __inlineCall(foo(5, 900)) + ret_copy1;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 0; i < a; ++i)
  {
    c = c + b;
  }

  return c + 1;
}

