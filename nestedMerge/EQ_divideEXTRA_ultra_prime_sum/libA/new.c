int client(int c, int d)
{
  int INLINED_RET_0;
  int ret;
  if (d == 0)
  {
    ret = 0;
  }
  else
  {
    int n_copy0 = c;
    int i_copy0 = 0;
    int sum_copy0 = 0;
    while (i_copy0 <= n_copy0)
    {
      if (lib(i_copy0) == 0)
      {
        sum_copy0 += i_copy0;
      }

      i_copy0++;
    }

    INLINED_RET_0 = lib(sum_copy0) == 0;
    ret = INLINED_RET_0;
  }

  return ret;
}

int lib(int a)
{
  int i = 2;
  int count = 0;
  while (i < a)
  {
    if ((a % i) != 0)
    {
      count = 1;
    }

    i++;
  }

  return count;
}


