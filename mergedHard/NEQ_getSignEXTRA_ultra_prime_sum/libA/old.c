int lib(int x)
{
  if (x == 0)
    return 0;

  if (x < 0)
    return -1;
  else
    return 1;

}

int client(int x, int n_copy1)
{
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

  return lib(x) + (lib(sum_copy1) == 0);
}
