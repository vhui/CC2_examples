extern int __inlineCall(int);
int foo(int a, int b);
int clientmain()
{
  int n_copy1 = __inlineCall(foo(5, 900));
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

  return sum_copy1;
}

int foo(int a, int b)
{
  int c = b + a;
  return c;
}
