int lib(int x)
{
  if (x <= 0)
    return -1;
  else
    return 1;

}

int client(int x)
{
  int x_copy1 = lib(x);
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
