int clientmain()
{
  int INLINED_RET_0;
  int x_copy0 = 5;
  int ret_copy0;
  if (lib(x_copy0) == 0)
  {
    ret_copy0 = 1;
  }
  else
  {
    ret_copy0 = 0;
  }

  INLINED_RET_0 = ret_copy0;
  return INLINED_RET_0;
}

int lib(int x)
{
  return (x + 1) % 2;
}

