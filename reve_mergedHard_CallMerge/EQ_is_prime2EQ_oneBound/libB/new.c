extern int __inlineCall(int);
int lib(int x)
{
  if (x > 11)
    return 11;
  else
    return x - 1;

}

int client(unsigned int x)
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

  int x_copy1 = ret;
  int ret_copy1;
  if ((x_copy1 < (-100)) || (x_copy1 > 100))
  {
    ret_copy1 = x_copy1;
  }
  else
  {
    if (x_copy1 > __inlineCall(lib(x_copy1)))
      ret_copy1 = x_copy1;
    else
      ret_copy1 = __inlineCall(lib(x_copy1));

  }

  return ret_copy1;
}
