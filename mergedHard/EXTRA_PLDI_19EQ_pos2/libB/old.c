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

int client(unsigned int n, unsigned int m, int x_copy1)
{
  int k = 0;
  int i = 0;
  while (i < n)
  {
    k = k + lib(m);
    i++;
  }

  int ret_copy1;
  if (x_copy1 > 0)
  {
    ret_copy1 = -lib(-x_copy1);
  }
  else
  {
    ret_copy1 = lib(x_copy1);
  }

  return k + ret_copy1;
}

