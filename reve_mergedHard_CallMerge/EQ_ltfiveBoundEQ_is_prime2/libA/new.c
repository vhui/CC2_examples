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

  unsigned int x_copy1 = ret;
  int ret_copy1;
  if (x_copy1 < 19)
  {
    ret_copy1 = __inlineCall(lib(20));
  }
  else
  {
    ret_copy1 = __inlineCall(lib(x_copy1));
  }

  return ret_copy1;
}

