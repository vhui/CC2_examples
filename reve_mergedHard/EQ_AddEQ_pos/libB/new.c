extern int __inlineCall(int);
int lib(int x)
{
  if (x < 0)
  {
    return -x;
  }
  else
  {
    return x;
  }

}

int clientmain(int x_copy1)
{
  int ret_copy1;
  if (x_copy1 > 0)
  {
    ret_copy1 = -__inlineCall(lib(-x_copy1));
  }
  else
  {
    ret_copy1 = __inlineCall(lib(x_copy1));
  }

  return __inlineCall(lib(5)) + ret_copy1;
}

