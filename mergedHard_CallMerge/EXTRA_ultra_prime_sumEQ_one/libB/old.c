int lib(int x)
{
  if (x > 10)
    return 11;
  else
    return x;

}

int client(int n)
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

  int x_copy1 = lib(sum) == 0;
  int ret_copy1;
  if (x_copy1 > lib(x_copy1))
    ret_copy1 = x_copy1;
  else
    ret_copy1 = lib(x_copy1);

  return ret_copy1;
}

