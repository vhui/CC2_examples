extern int __inlineCall(int);
int lib(int x)
{
  if (x < 0)
    return 0;
  else
    return x;

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
    if (x < 0)
    {
      ret = (-__inlineCall(lib((-x) * 5))) / 5;
    }
    else
    {
      ret = (__inlineCall(lib((x + 1) * 5)) / 5) - 1;
    }

  }

  return ret + __inlineCall(lib(5));
}

