extern int __inlineCall(int);
int lib(int x)
{
  if (x < 0)
  {
    return -x;
  }

  int counter = 0;
  while (x > 0)
  {
    x += 1;
    counter += 1;
  }

  return counter;
}

int client(int x, unsigned int x_copy1)
{
  int ret = -x;
  if (x < 0)
  {
    ret = __inlineCall(lib(x));
  }

  int ret_copy1;
  if (x_copy1 < 19)
  {
    ret_copy1 = __inlineCall(lib(20));
  }
  else
  {
    ret_copy1 = __inlineCall(lib(x_copy1));
  }

  return ret + ret_copy1;
}

