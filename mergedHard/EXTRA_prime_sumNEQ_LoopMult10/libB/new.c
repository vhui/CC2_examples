int foo(int a, int b);
int client(int n, int x_copy1)
{
  int i = 0;
  int sum = 0;
  while (i <= n)
  {
    if (foo(i, i) == 0)
    {
      sum += i;
    }

    i++;
  }

  sum;
  int ret_copy1 = 0;
  if ((x_copy1 >= 9) && (x_copy1 < 12))
    ret_copy1 = foo(x_copy1, 10);

  return sum + ret_copy1;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= a; ++i)
    c += b;

  return c;
}

