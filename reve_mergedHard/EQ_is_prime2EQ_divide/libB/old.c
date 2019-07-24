extern int __inlineCall(int);
int lib(int x, int y)
{
  return x / y;
}

int client(unsigned int x, int c_copy1, int d_copy1)
{
  int ret;
  if (x < 19)
  {
    ret = __inlineCall(lib(20, 1));
  }
  else
  {
    ret = __inlineCall(lib(x, 1));
  }

  int ret_copy1;
  if (d_copy1 == 0)
  {
    ret_copy1 = 0;
  }
  else
  {
    ret_copy1 = __inlineCall(lib(c_copy1, d_copy1));
  }

  return ret + ret_copy1;
}
