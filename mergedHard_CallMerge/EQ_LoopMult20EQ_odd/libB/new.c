int lib(int x)
{
  return (x + 1) % 2;
}

int clientmain(int x)
{
  int ret = 0;
  if ((x >= 18) && (x < 22))
    ret = lib(x);

  int x_copy1 = ret;
  int ret_copy1;
  if (lib(x_copy1) == 0)
  {
    ret_copy1 = 1;
  }
  else
  {
    ret_copy1 = 0;
  }

  return ret_copy1;
}

