int client(int x)
{
  int INLINED_RET_0;
  int ret;
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
  if (__inlineCall(INLINED_RET_0) == 0)
  {
    ret = 1;
  }
  else
  {
    ret = 0;
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
    ret = x;
  }

  return ret;
}


