extern int __inlineCall(int);
int lib(int x)
{
  int ret;
  if (x <= 0)
    ret = -1;
  else
    ret = 1;

  return ret;
}

int client(int x, unsigned int x_copy1)
{
  int ret_copy1;
  if (x_copy1 < 19)
  {
    ret_copy1 = __inlineCall(lib(20));
  }
  else
  {
    ret_copy1 = __inlineCall(lib(x_copy1));
  }

  return __inlineCall(lib(x)) + ret_copy1;
}

