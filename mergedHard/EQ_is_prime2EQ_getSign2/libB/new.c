int lib(int x)
{
  if (x <= 0)
    return -1;
  else
    return 1;

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

  int ret_copy1 = x_copy1;
  if (x_copy1 > 0)
  {
    ret_copy1 = lib(x_copy1);
  }

  return ret + ret_copy1;
}

