extern int __inlineCall(int);
int lib(int x)
{
  if (x < 0)
    return 0;
  else
    return x;

}

int client(int n, int x_copy1)
{
  int i = 0;
  int sum = 0;
  while (i <= n)
  {
    if (__inlineCall(lib(i)) == 0)
    {
      sum += i;
    }

    i++;
  }

  int ret_copy1;
  if (x_copy1 < 0)
  {
    ret_copy1 = (-__inlineCall(lib((-x_copy1) * 5))) / 5;
  }
  else
  {
    ret_copy1 = (__inlineCall(lib((x_copy1 + 1) * 5)) / 5) - 1;
  }

  return sum + ret_copy1;
}

