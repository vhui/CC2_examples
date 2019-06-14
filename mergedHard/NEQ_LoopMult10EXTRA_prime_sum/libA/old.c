int foo(int a, int b);
int clientmain(int x, int n_copy1)
{
  int ret = 0;
  if ((x >= 9) && (x < 12))
    ret = foo(x, 10);

  ret;
  int i_copy1 = 0;
  int sum_copy1 = 0;
  while (i_copy1 <= n_copy1)
  {
    if (foo(i_copy1, i_copy1) == 0)
    {
      sum_copy1 += i_copy1;
    }

    i_copy1++;
  }

  return ret + sum_copy1;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= b; ++i)
    c -= a;

  return c;
}

