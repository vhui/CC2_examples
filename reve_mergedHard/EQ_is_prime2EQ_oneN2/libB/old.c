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

int client(unsigned int x, int x_copy1)
{
  int ret;
  if (x < 19)
  {
    ret = __inlineCall(lib(20));
  }
  else
  {
    ret = __inlineCall(lib(x));
  }

  int ret_copy1;
  if (x_copy1 > __inlineCall(lib(x_copy1)))
    ret_copy1 = x_copy1;
  else
    ret_copy1 = __inlineCall(lib(x_copy1));

  return ret + ret_copy1;
}
