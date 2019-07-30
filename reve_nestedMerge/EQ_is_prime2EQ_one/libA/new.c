int client(unsigned int x)
{
  int INLINED_RET_0;
  int INLINED_RET_1;
  int ret;
  if (x < 19)
  {
    int x_copy0 = 20;
    int ret_copy0;
    if (x_copy0 > __inlineCall(lib(x_copy0)))
    {
      ret_copy0 = x_copy0;
    }
    else
    {
      ret_copy0 = __inlineCall(lib(x_copy0));
    }

    INLINED_RET_0 = ret_copy0;
    ret = __inlineCall(INLINED_RET_0);
  }
  else
  {
    int x_copy1 = x;
    int ret_copy1;
    if (x_copy1 > __inlineCall(lib(x_copy1)))
    {
      ret_copy1 = x_copy1;
    }
    else
    {
      ret_copy1 = __inlineCall(lib(x_copy1));
    }

    INLINED_RET_1 = ret_copy1;
    ret = __inlineCall(INLINED_RET_1);
  }

  return ret;
}

int lib(int x)
{
  int ret;
  if (x > 10)
    ret = 12;
  else
    ret = x + 1;

  return ret;
}


