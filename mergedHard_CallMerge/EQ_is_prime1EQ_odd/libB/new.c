int lib(int x)
{
  return (x + 1) % 2;
}

int client(unsigned int x)
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

