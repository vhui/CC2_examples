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

  return lib(5, 900);
}

