int client(int n, int n_1)
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

  sum;
  int i_1 = 0;
  int sum_1 = 0;
  while (i_1 <= n_1)
  {
    if (lib(i) == 0)
    {
      sum_1 += i_1;
    }

    i_1++;
  }

  return sum_1;
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

