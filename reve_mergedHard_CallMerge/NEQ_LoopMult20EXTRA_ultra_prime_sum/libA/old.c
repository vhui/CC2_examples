extern int __inlineCall(int);
int foo(int a, int b);
int clientmain(int x)
{
  int ret = 0;
  if ((x >= 18) && (x < 22))
    ret = __inlineCall(foo(x, 20));

  int n_copy1 = ret;
  int i_copy1 = 0;
  int sum_copy1 = 0;
  while (i_copy1 <= n_copy1)
  {
    if (__inlineCall(foo(i_copy1, i_copy1)) == 0)
    {
      sum_copy1 += i_copy1;
    }

    i_copy1++;
  }

  return __inlineCall(foo(sum_copy1, sum_copy1)) == 0;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= b; ++i)
    c -= a;

  return c;
}

