int lib(int x, int y)
{
  if (y == 0)
  {
    return 0;
  }

  return x / y;
}

int client(int n)
{
  int i = 0;
  int sum = 0;
  while (i <= n)
  {
    if (lib(i, i) == 0)
    {
      sum += i;
    }

    i++;
  }

  int c_copy1 = lib(sum, sum) == 0;
  int d_copy1 = lib(sum, sum) == 0;
  int ret_copy1;
  if (d_copy1 == 0)
  {
    ret_copy1 = 0;
  }
  else
  {
    ret_copy1 = lib(c_copy1, d_copy1);
  }

  return ret_copy1;
}

