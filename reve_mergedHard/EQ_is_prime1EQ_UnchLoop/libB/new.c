extern int __inlineCall(int);
int foo(int a, int b);
int client(unsigned int x)
{
  return __inlineCall(foo(x, 0)) + __inlineCall(foo(5, 900));
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
