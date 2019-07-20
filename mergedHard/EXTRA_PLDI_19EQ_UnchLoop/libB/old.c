int foo(int a, int b);
int client(unsigned int n, unsigned int m)
{
  int k = 0;
  int i = 0;
  while (i < n)
  {
    k = k + foo(m, m);
    i++;
  }

  return k + foo(5, 900);
}

int foo(int a, int b)
{
  int c = 1;
  for (int i = 0; i < a; ++i)
  {
    c = c + b;
  }

  return c;
}

