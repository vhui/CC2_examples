int lib(int x, int y)
{
  return x / y;
}

int client(int c, int d)
{
  int ret;
  if (d == 0)
  {
    ret = 0;
  }
  else
  {
    ret = lib(c, d);
  }

  int x_copy1 = ret;
  int ret_copy1 = 0;
  if ((x_copy1 >= 18) && (x_copy1 < 22))
    ret_copy1 = lib(x_copy1, 20);

  return ret_copy1;
}

