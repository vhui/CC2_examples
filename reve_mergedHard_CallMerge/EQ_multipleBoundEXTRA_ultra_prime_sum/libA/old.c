extern int __inlineCall(int);
int lib(int x)
{
  return x % 5;
}

int client(int x)
{
  int ret;
  if ((x < (-100)) || (x > 100))
  {
    ret = x;
  }
  else
  {
    x = (x * 5) * 6;
    if (__inlineCall(lib(x)) == 0)
    {
      ret = 1;
    }
    else
    {
      ret = 0;
    }

  }

  int n_copy1 = ret;
  int i_copy1 = 0;
  int sum_copy1 = 0;
  while (i_copy1 <= n_copy1)
  {
    if (__inlineCall(lib(i_copy1)) == 0)
    {
      sum_copy1 += i_copy1;
    }

    i_copy1++;
  }

  return __inlineCall(lib(sum_copy1)) == 0;
}

