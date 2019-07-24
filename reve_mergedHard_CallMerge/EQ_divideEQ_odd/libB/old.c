extern int __inlineCall(int);
int lib(int x)
{
  int counter = 0;
  while ((x % 2) == 0)
  {
    x = x / 2;
    counter++;
  }

  return counter;
}

int client(int c, int d)
{
  int ret;
  if (d == 0)
  {
    ret = 0;
  }
  else
  {
    ret = __inlineCall(lib(c));
  }

  int x_copy1 = ret;
  int ret_copy1;
  if (__inlineCall(lib(x_copy1)) == 0)
  {
    ret_copy1 = 1;
  }
  else
  {
    ret_copy1 = 0;
  }

  return ret_copy1;
}
