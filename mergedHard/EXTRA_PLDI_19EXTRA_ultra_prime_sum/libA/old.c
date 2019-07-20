int client(unsigned int n, unsigned int m, int n_copy1)
{
  int k = 0;
  int i = 0;
  while (i < n)
  {
    k = k + lib(m);
    i++;
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

  return k + (lib(sum_copy1) == 0);
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

