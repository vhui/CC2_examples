extern int __inlineCall(int);
int foo(int a, int b);
int clientmain()
{
  unsigned int x_copy1 = __inlineCall(foo(5, 900));
  return __inlineCall(foo(x_copy1, 0));
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

