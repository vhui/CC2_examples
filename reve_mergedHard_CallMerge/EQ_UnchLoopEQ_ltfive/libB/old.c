extern int __inlineCall(int);
int lib(int x)
{
  if (x < 5)
    return 5;
  else
    return x;

}

int clientmain()
{
  int x_copy1 = __inlineCall(lib(5));
  int ret_copy1;
  if (x_copy1 < 0)
  {
    ret_copy1 = (-__inlineCall(lib((-x_copy1) * 5))) / 5;
  }
  else
  {
    ret_copy1 = (__inlineCall(lib((x_copy1 + 1) * 5)) / 5) - 1;
  }

  return ret_copy1;
}

