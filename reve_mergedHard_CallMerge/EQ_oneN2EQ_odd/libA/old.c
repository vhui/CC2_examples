extern int __inlineCall(int);
int lib(int x)
{
  int ret;
  if (x > 10)
    ret = 11;
  else
    ret = x;

  return ret;
}

int client(int x)
{
  int ret;
  if (x > __inlineCall(lib(x)))
    ret = x;
  else
    ret = __inlineCall(lib(x));

  int x_copy1 = ret;
  int ret_copy1;
  if (__inlineCall(lib(x_copy1)) == 0)
  {
    ret_copy1 = 1;
  }
  else
  {
    ret_copy1 = 0;
  }

  return ret_copy1;
}

