extern int __inlineCall(int);
int lib(int x)
{
  if (x <= 0)
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
    if (__inlineCall(lib(i_copy1)) == 0)
    {
      sum_copy1 += i_copy1;
    }

    i_copy1++;
  }

  return __inlineCall(lib(x)) + sum_copy1;
}

