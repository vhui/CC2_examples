int lib(int x)
{
  int ret = x;
  if (x < 0)
  {
    ret = -x;
  }

  return ret;
}

int client(int x, int x_copy1)
{
  int ret;
  if ((x < (-100)) || (x > 100))
  {
    ret = x;
  }
  else
  {
    x = (x * 5) * 6;
    if (lib(x) == 0)
    {
      ret = 1;
    }
    else
    {
      ret = 0;
    }

  }

  int ret_copy1 = -x_copy1;
  if (x_copy1 < 0)
  {
    ret_copy1 = lib(x_copy1);
  }

  return ret + ret_copy1;
}

