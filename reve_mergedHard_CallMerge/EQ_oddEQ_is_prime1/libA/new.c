extern int __inlineCall(int);
int lib(int x)
{
  return (x + 1) % 2;
}

int client(int x)
{
  int ret;
  if (__inlineCall(lib(x)) == 0)
  {
    ret = 1;
  }
  else
  {
    ret = 0;
  }

  int x_copy1 = ret;
  return __inlineCall(lib(x_copy1));
}

