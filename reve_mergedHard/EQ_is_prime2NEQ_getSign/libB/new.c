extern int __inlineCall(int);
int lib(int x)
{
  if (x <= 0)
    return -1;
  else
    return 1;

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

  return ret + __inlineCall(lib(x_copy1));
}

