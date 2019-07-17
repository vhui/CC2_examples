int lib(int x)
{
  if (x > 10)
    return 11;
  else
    return x;

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

  return ret + ret_copy1;
}

