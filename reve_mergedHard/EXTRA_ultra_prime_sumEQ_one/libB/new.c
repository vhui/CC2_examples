extern int __inlineCall(int);
int lib(int x)
{
  if (x > 10)
    return 12;
  else
    return x + 1;

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
  if (x_copy1 > __inlineCall(lib(x_copy1)))
    ret_copy1 = x_copy1;
  else
    ret_copy1 = __inlineCall(lib(x_copy1));

  return (__inlineCall(lib(sum)) == 0) + ret_copy1;
}
