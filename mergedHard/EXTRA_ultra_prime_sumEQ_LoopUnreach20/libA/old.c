int lib(int a)
{
  int i = 2;
  int count = 0;
  while (i < a)
  {
    if ((a % i) != 0)
    {
      count++;
    }

    i++;
  }

  return count;
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

  int ret_copy1 = 0;
  if ((x_copy1 >= 18) && (x_copy1 < 22))
    ret_copy1 = lib(x_copy1);

  return (lib(sum) == 0) + ret_copy1;
}

