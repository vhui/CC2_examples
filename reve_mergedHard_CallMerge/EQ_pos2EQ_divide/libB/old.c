extern int __inlineCall(int);
int lib(int x, int y)
{
  return x / y;
}

int client(int x)
{
  int ret;
  if (x > 0)
  {
    ret = -__inlineCall(lib(-x, -x));
  }
  else
  {
    ret = __inlineCall(lib(x, x));
  }

  int c_copy1 = ret;
  int d_copy1 = ret;
  int ret_copy1;
  if (d_copy1 == 0)
  {
    ret_copy1 = 0;
  }
  else
  {
    ret_copy1 = __inlineCall(lib(c_copy1, d_copy1));
  }

  return ret_copy1;
}
