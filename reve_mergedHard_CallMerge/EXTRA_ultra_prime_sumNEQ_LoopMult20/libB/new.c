extern int __inlineCall(int);
int foo(int a, int b);
int client(int n)
{
  int i = 0;
  int sum = 0;
  while (i <= n)
  {
    if (__inlineCall(foo(i, i)) == 0)
    {
      sum += i;
    }

    i++;
  }

  int x_copy1 = __inlineCall(foo(sum, sum)) == 0;
  int ret_copy1 = 0;
  if ((x_copy1 >= 18) && (x_copy1 < 22))
    ret_copy1 = __inlineCall(foo(x_copy1, 20));

  return ret_copy1;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= a; ++i)
    c += b;

  return c;
}
