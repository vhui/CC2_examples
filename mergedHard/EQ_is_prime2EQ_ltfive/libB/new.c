int lib(int x)
{
  int ret;
  if (x < 0)
    ret = 0;
  else
    ret = x;

  return ret;
}

int client(unsigned int x, int x_copy1)
{
  int ret;
  if (x < 19)
  {
    ret = lib(20);
  }
  else
  {
    ret = lib(x);
  }

  int ret_copy1;
  if (x_copy1 < 0)
  {
    ret_copy1 = (-lib((-x_copy1) * 5)) / 5;
  }
  else
  {
    ret_copy1 = (lib((x_copy1 + 1) * 5) / 5) - 1;
  }

  return ret + ret_copy1;
}

