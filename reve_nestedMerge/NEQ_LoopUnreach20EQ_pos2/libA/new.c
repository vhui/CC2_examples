extern int __inlineCall(int);

int clientmain(int x)
{
  int INLINED_RET_0;
  int ret = 0;
  if ((x >= 18) && (x < 22))
  {
    int x_copy0 = x;
    int ret_copy0;
    if (x_copy0 > 0)
    {
      ret_copy0 = -__inlineCall(lib(-x_copy0));
    }
    else
    {
      ret_copy0 = __inlineCall(lib(x_copy0));
    }

    INLINED_RET_0 = ret_copy0;
    ret = INLINED_RET_0;
  }

  return ret;
}

int lib(int x)
{
  int ret;
  if (x < 0)
  {
    ret = -x;
  }
  else
  {
    while (x >= 0)
    {
      x = x;
    }

    ret = x;
  }

  return ret;
}

