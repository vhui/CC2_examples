int clientmain()
{
  int INLINED_RET_0;
  int x_copy0 = 5;
  int ret_copy0 = x_copy0;
  if (x_copy0 > 0)
  {
    ret_copy0 = lib(x_copy0);
  }

  INLINED_RET_0 = ret_copy0;
  return INLINED_RET_0;
}

int lib(int x)
{
  int ret;
  if (x == 0)
    ret = 0;
  else
    if (x < 0)
    ret = -1;
  else
    ret = 1;


  return ret;
}


