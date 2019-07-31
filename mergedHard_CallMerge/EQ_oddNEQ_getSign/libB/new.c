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
  if (lib(x) == 0)
  {
    ret = 1;
  }
  else
  {
    ret = 0;
  }

  int x_copy1 = ret;
  return lib(x_copy1);
}

