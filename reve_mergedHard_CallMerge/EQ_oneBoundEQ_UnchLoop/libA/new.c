extern int __inlineCall(int);
int lib(int x)
{
  if (x > 11)
    return 11;
  else
    return x - 1;

}

int client(int x)
{
  int ret;
  if ((x < (-100)) || (x > 100))
  {
    ret = x;
  }
  else
  {
    if (x > __inlineCall(lib(x)))
      ret = x;
    else
      ret = __inlineCall(lib(x));

  }

  return __inlineCall(lib(5));
}

