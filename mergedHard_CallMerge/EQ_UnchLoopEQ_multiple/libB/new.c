int lib(int x)
{
  return x % 6;
}

int clientmain()
{
  int x_copy1 = lib(5);
  int ret_copy1;
  x_copy1 = (x_copy1 * 5) * 6;
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

