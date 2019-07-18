int lib(int x)
{
  if (x <= 0)
    return -1;
  else
    return 1;

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
  return lib(x_copy1);
}

