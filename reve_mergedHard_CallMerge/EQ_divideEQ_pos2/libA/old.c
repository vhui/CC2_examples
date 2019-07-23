extern int __inlineCall(int);
int lib(int x, int y)
{
  return x / y;
}

int client(int c, int d)
{
  int ret;
  if (d == 0)
  {
    ret = 0;
  }
  else
  {
    ret = __inlineCall(lib(c, d));
  }

  int x_copy1 = ret;
  int ret_copy1;
  if (x_copy1 > 0)
  {
    ret_copy1 = -__inlineCall(lib(-x_copy1, -x_copy1));
  }
  else
  {
    ret_copy1 = __inlineCall(lib(x_copy1, x_copy1));
  }

  return ret_copy1;
}

