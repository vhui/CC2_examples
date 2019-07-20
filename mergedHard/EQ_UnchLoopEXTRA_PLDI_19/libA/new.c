int foo(int a, int b);
int clientmain(unsigned int n_copy1, unsigned int m_copy1)
{
  int k_copy1 = 0;
  int i_copy1 = 0;
  while (i_copy1 < n_copy1)
  {
    k_copy1 = k_copy1 + foo(m_copy1, m_copy1);
    i_copy1++;
  }

  return foo(5, 900) + k_copy1;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 0; i < a; ++i)
  {
    c = c + b;
  }

  return c + 1;
}

