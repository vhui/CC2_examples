extern int __inlineCall(int);
int lib(int x)
{
  return x % 6;
}

int client(int x, unsigned int x_copy1)
{
  int ret;
  x = (x * 5) * 6;
  if (__inlineCall(lib(x)) == 0)
  {
    ret = 1;
  }
  else
  {
    ret = 0;
  }

  int ret_copy1;
  if (x_copy1 < 19)
  {
    ret_copy1 = __inlineCall(lib(20));
  }
  else
  {
    ret_copy1 = __inlineCall(lib(x_copy1));
  }

  return ret + ret_copy1;
}

