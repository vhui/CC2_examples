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
  if (lib(x) == 0)
  {
    ret = 1;
  }
  else
  {
    ret = 0;
  }

  int x_copy1 = ret;
  int ret_copy1;
  if ((x_copy1 < (-100)) || (x_copy1 > 100))
  {
    ret_copy1 = x_copy1;
  }
  else
  {
    if (x_copy1 > lib(x_copy1))
      ret_copy1 = x_copy1;
    else
      ret_copy1 = lib(x_copy1);

  }

  return ret_copy1;
}

