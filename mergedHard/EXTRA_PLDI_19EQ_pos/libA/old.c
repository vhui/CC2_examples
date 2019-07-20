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

int lib(int a)
{
  int count = 0;
  int j = 0;
  while (j < a)
  {
    count++;
    j++;
  }

  return count;
}

