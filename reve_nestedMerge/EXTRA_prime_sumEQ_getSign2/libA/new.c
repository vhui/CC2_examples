int client(int n)
{
  int INLINED_RET_0;
  int i = 0;
  int sum = 0;
  while (i <= n)
  {
    int x_copy0 = i;
    int ret_copy0 = x_copy0;
    if (x_copy0 > 0)
    {
      ret_copy0 = __inlineCall(lib(x_copy0));
    }

    INLINED_RET_0 = ret_copy0;
    if (__inlineCall(INLINED_RET_0) == 0)
    {
      sum += i;
    }

    i++;
  }

  return sum;
}

int lib(int x)
{
  int ret;
  if (x <= 0)
    ret = -1;
  else
    ret = 1;

  return ret;
}


