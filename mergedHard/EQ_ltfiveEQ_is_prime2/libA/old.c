int lib(int x)
{
  if (x < 5)
    return 5;
  else
    return x;

}

int client(int x, unsigned int x_copy1)
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

  int ret_copy1;
  if (x_copy1 < 19)
  {
    ret_copy1 = lib(20);
  }
  else
  {
    ret_copy1 = lib(x_copy1);
  }

  return ret + ret_copy1;
}

