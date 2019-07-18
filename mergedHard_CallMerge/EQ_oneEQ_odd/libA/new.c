int lib(int x)
{
  if (x > 10)
    return 12;
  else
    return x + 1;

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

