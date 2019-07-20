int client(int n, unsigned int n_copy1, unsigned int m_copy1)
{
  int i = 0;
  int sum = 0;
  while (i <= n)
  {
    if (lib(i) == 0)
    {
      sum += i;
    }

    i++;
  }

  int k_copy1 = 0;
  int i_copy1 = 0;
  while (i_copy1 < n_copy1)
  {
    k_copy1 = k_copy1 + lib(m_copy1);
    i_copy1++;
  }

  return sum + k_copy1;
}

int lib(int a)
{
  int count = 0;
  int j = 0;
  while (j < a)
  {
    count++;
    j++;
  }

  return count;
}

