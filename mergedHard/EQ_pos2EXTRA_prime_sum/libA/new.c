int lib(int x)
{
  if (x < 0)
  {
    return -x;
  }
  else
  {
    while (x >= 0)
    {
      x = x;
    }

    return x;
  }

}

int client(int x, int n_copy1)
{
  int ret;
  if (x > 0)
  {
    ret = -lib(-x);
  }
  else
  {
    ret = lib(x);
  }

  int i_copy1 = 0;
  int sum_copy1 = 0;
  while (i_copy1 <= n_copy1)
  {
    if (lib(i_copy1) == 0)
    {
      sum_copy1 += i_copy1;
    }

    i_copy1++;
  }

  return ret + sum_copy1;
}

