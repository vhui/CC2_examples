int lib(int x)
{
  return (x + 1) % 2;
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
  if (lib(x_copy1) == 0)
  {
    ret_copy1 = 1;
  }
  else
  {
    ret_copy1 = 0;
  }

  return k + ret_copy1;
}

