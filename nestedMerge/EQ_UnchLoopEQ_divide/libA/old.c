int lib(int x, int y)
{
  return x / y;
}

int clientmain()
{
  int INLINED_RET_0;
  int d_copy0 = 900;
  int c_copy0 = 5;
  int ret_copy0;
  if (d_copy0 == 0)
  {
    ret_copy0 = 0;
  }
  else
  {
    ret_copy0 = lib(c_copy0, d_copy0);
  }

  INLINED_RET_0 = ret_copy0;
  return INLINED_RET_0;
}


