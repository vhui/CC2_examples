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

int clientmain(int x)
{
  int ret = 0;
  if ((x >= 18) && (x < 22))
    ret = __inlineCall(lib(x));

  int x_copy1 = ret;
  return __inlineCall(lib(x_copy1));
}

