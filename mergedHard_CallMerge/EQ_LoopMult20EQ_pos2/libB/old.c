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

int clientmain(int x)
{
  int ret = 0;
  if ((x >= 18) && (x < 22))
    ret = lib(x);

  int x_copy1 = ret;
  int ret_copy1;
  if (x_copy1 > 0)
  {
    ret_copy1 = -lib(-x_copy1);
  }
  else
  {
    ret_copy1 = lib(x_copy1);
  }

  return ret_copy1;
}

