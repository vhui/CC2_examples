int lib(int x)
{
  if (x < 0)
  {
    return -x;
  }
  else
  {
    while (x >= 0)
    {
      x = x;
    }

    return x;
  }

}

int client(int x)
{
  int ret;
  if (x < 0)
  {
    ret = (-lib((-x) * 5)) / 5;
  }
  else
  {
    ret = (lib((x + 1) * 5) / 5) - 1;
  }

  int x_copy1 = ret;
  int ret_copy1;
  if (x_copy1 > 0)
  {
    ret_copy1 = -lib(-x_copy1);
  }
  else
  {
    ret_copy1 = lib(x_copy1);
  }

  return ret_copy1;
}
