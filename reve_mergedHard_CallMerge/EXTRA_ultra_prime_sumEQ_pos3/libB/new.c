extern int __inlineCall(int);
int lib(int x)
{
  if (x < 0)
  {
    return -x;
  }

  return x;
}

int client(int n)
{
  int i = 0;
  int sum = 0;
  while (i <= n)
  {
    if (__inlineCall(lib(i)) == 0)
    {
      sum += i;
    }

    i++;
  }

  int x_copy1 = __inlineCall(lib(sum)) == 0;
  int ret_copy1 = -x_copy1;
  if (x_copy1 < 0)
  {
    ret_copy1 = __inlineCall(lib(x_copy1));
  }

  return ret_copy1;
}

