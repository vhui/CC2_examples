extern int __inlineCall(int);
int client(int x, int n_copy1)
{
  int ret;
  if (x < 19)
  {
    ret = __inlineCall(lib(20));
  }
  else
  {
    ret = __inlineCall(lib(x));
  }

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

  return ret + sum_copy1;
}

int lib(int a)
{
  int i = 2;
  int count = 0;
  while (i < a)
  {
    if ((a % i) != 0)
    {
      count++;
    }

    i++;
  }

  return count;
}

