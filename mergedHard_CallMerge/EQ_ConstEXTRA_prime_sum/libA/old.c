int foo(int a, int b);
int clientmain()
{
  int n_copy1 = foo(5, 900);
  int i_copy1 = 0;
  int sum_copy1 = 0;
  while (i_copy1 <= n_copy1)
  {
    if (foo(i_copy1, i_copy1) == 0)
    {
      sum_copy1 += i_copy1;
    }

    i_copy1++;
  }

  return sum_copy1;
}

int foo(int a, int b)
{
  int c = a + b;
  return c + 3;
}

