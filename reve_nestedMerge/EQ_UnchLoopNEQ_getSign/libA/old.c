int clientmain()
{
  int INLINED_RET_0;
  int x_copy0 = 5;
  INLINED_RET_0 = __inlineCall(lib(x_copy0));
  return __inlineCall(INLINED_RET_0);
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


