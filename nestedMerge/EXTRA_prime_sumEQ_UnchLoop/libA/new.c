int foo(int a, int b)
{
  int c = 0;
  for (int i = 0; i < a; ++i)
  {
    c = c + b;
  }

  return c + 1;
}

int client(int n)
{
  int INLINED_RET_0;
  int i = 0;
  int sum = 0;
  while (i <= n)
  {
    INLINED_RET_0 = foo(5, 900);
    if (INLINED_RET_0 == 0)
    {
      sum += i;
    }

    i++;
  }

  return sum;
}


