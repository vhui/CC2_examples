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
  return sum + foo(2, 2);
}

int foo(int a, int b)
{
  int c = 0;
  if (a < 0)
  {
    for (int i = 1; i <= a; ++i)
      c += b;

  }

  return c;
}

