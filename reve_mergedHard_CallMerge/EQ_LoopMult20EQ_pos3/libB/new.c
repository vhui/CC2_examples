extern int __inlineCall(int);
int lib(int x)
{
  int ret = x;
  if (x < 0)
  {
    ret = -x;
  }

  return ret;
}

int clientmain(int x)
{
  int ret = 0;
  if ((x >= 18) && (x < 22))
    ret = __inlineCall(lib(x));

  int x_copy1 = ret;
  int ret_copy1 = -x_copy1;
  if (x_copy1 < 0)
  {
    ret_copy1 = __inlineCall(lib(x_copy1));
  }

  return ret_copy1;
}

