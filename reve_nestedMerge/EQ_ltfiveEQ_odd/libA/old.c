extern int __inlineCall(int);

int client(int x)
{
  int INLINED_RET_0;
  int INLINED_RET_1;
  int ret;
  if (x < 0)
  {
    int x_copy0 = (-x) * 5;
    int ret_copy0;
    if (__inlineCall(lib(x_copy0)) == 0)
    {
      ret_copy0 = 1;
    }
    else
    {
      ret_copy0 = 0;
    }

    INLINED_RET_0 = ret_copy0;
    ret = (-INLINED_RET_0) / 5;
  }
  else
  {
    int x_copy1 = (x + 1) * 5;
    int ret_copy1;
    if (__inlineCall(lib(x_copy1)) == 0)
    {
      ret_copy1 = 1;
    }
    else
    {
      ret_copy1 = 0;
    }

    INLINED_RET_1 = ret_copy1;
    ret = (INLINED_RET_1 / 5) - 1;
  }

  return ret;
}

int lib(int x)
{
  int counter = 0;
  while ((x % 2) == 0)
  {
    x = x / 2;
    counter++;
  }

  return counter;
}


