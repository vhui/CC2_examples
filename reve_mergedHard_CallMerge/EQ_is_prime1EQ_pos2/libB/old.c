extern int __inlineCall(int);
int lib(int x)
{
  int counter = 0;
  while (x < 0)
  {
    x++;
    counter++;
  }

  return counter;
}

int client(unsigned int x)
{
  int x_copy1 = __inlineCall(lib(x));
  int ret_copy1;
  if (x_copy1 > 0)
  {
    ret_copy1 = -__inlineCall(lib(-x_copy1));
  }
  else
  {
    ret_copy1 = __inlineCall(lib(x_copy1));
  }

  return ret_copy1;
}
