int client(unsigned int x)
{
  int INLINED_RET_0;
  int INLINED_RET_1;
  int ret;
  if (x < 19)
  {
    int x_copy0 = 20;
    int ret_copy0;
    if ((x_copy0 < (-100)) || (x_copy0 > 100))
    {
      ret_copy0 = x_copy0;
    }
    else
    {
      x_copy0 = (x_copy0 * 5) * 6;
      if (lib(x_copy0) == 0)
      {
        ret_copy0 = 1;
      }
      else
      {
        ret_copy0 = 0;
      }

    }

    INLINED_RET_0 = ret_copy0;
    ret = INLINED_RET_0;
  }
  else
  {
    int x_copy1 = x;
    int ret_copy1;
    if ((x_copy1 < (-100)) || (x_copy1 > 100))
    {
      ret_copy1 = x_copy1;
    }
    else
    {
      x_copy1 = (x_copy1 * 5) * 6;
      if (lib(x_copy1) == 0)
      {
        ret_copy1 = 1;
      }
      else
      {
        ret_copy1 = 0;
      }

    }

    INLINED_RET_1 = ret_copy1;
    ret = INLINED_RET_1;
  }

  return ret;
}

int lib(int x)
{
  return x % 5;
}

