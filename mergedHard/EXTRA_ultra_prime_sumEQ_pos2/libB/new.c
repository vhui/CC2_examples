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

int client(int n, int x_copy1)
{
  int i = 0;
  int sum = 0;
  while (i <= n)
  {
    if (lib(i) == 0)
    {
      sum += i;
    }

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

  return (lib(sum) == 0) + ret_copy1;
}
