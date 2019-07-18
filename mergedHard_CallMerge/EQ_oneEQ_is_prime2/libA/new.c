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

  unsigned int x_copy1 = ret;
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

