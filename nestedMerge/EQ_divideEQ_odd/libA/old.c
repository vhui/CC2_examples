int client(int c, int d)
{
  int INLINED_RET_0;
  int ret;
  if (d == 0)
  {
    ret = 0;
  }
  else
  {
    int x_copy0 = c;
    int ret_copy0;
    if (lib(x_copy0) == 0)
    {
      ret_copy0 = 1;
    }
    else
    {
      ret_copy0 = 0;
    }

    INLINED_RET_0 = ret_copy0;
    ret = INLINED_RET_0;
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


