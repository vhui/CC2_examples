int lib(int x)
{
  int ret;
  if (x > 10)
    ret = 11;
  else
    ret = x;

  return ret;
}

int client(int x)
{
  int ret;
  if (x > lib(x))
    ret = x;
  else
    ret = lib(x);

  int x_copy1 = ret;
  int ret_copy1;
  if (x_copy1 < 19)
  {
    ret_copy1 = lib(20);
  }
  else
  {
    ret_copy1 = lib(x_copy1);
  }

  return ret_copy1;
}

