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

int client(int x)
{
  int ret;
  if (x > 0)
  {
    ret = -__inlineCall(lib(-x));
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
    if (x_copy1 < 0)
    {
      ret_copy1 = (-__inlineCall(lib((-x_copy1) * 5))) / 5;
    }
    else
    {
      ret_copy1 = (__inlineCall(lib((x_copy1 + 1) * 5)) / 5) - 1;
    }

  }

  return ret_copy1;
}
