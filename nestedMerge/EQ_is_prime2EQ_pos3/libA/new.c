int client(unsigned int x)
{
  int INLINED_RET_1;
  int INLINED_RET_0;
  int ret;
  if (x < 19)
  {
    int x_copy0 = 20;
    int ret_copy0 = -x_copy0;
    if (x_copy0 < 0)
    {
      ret_copy0 = lib(x_copy0);
    }

    INLINED_RET_0 = ret_copy0;
    ret = INLINED_RET_0;
  }
  else
  {
    int x_copy1 = x;
    int ret_copy1 = -x_copy1;
    if (x_copy1 < 0)
    {
      ret_copy1 = lib(x_copy1);
    }

    INLINED_RET_1 = ret_copy1;
    ret = INLINED_RET_1;
  }

  return ret;
}

int lib(int x)
{
  int ret = x;
  if (x < 0)
  {
    ret = -x;
  }

  return ret;
}

