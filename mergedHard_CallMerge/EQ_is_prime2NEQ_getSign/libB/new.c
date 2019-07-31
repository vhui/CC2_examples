int lib(int x)
{
  int ret;
  if (x <= 0)
    ret = -1;
  else
    ret = 1;

  return ret;
}

int client(int x)
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

  int x_copy1 = ret;
  return lib(x_copy1);
}

