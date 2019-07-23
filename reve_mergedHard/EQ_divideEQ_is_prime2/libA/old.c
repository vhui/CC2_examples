extern int __inlineCall(int);
int lib(int x, int y)
{
  return x / y;
}

int client(int c, int d, unsigned int x_copy1)
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

  int ret_copy1;
  if (x_copy1 < 19)
  {
    ret_copy1 = __inlineCall(lib(20, 1));
  }
  else
  {
    ret_copy1 = __inlineCall(lib(x_copy1, 1));
  }

  return ret + ret_copy1;
}

