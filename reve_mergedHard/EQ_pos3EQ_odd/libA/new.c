extern int __inlineCall(int);
int lib(int x)
{
  if (x < 0)
  {
    return -x;
  }

  return x;
}

int client(int x, int x_copy1)
{
  int ret = -x;
  if (x < 0)
  {
    ret = __inlineCall(lib(x));
  }

  int ret_copy1;
  if (__inlineCall(lib(x_copy1)) == 0)
  {
    ret_copy1 = 1;
  }
  else
  {
    ret_copy1 = 0;
  }

  return ret + ret_copy1;
}
