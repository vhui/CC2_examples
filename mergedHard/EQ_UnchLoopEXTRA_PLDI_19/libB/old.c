int clientmain(unsigned int n_copy1, unsigned int m_copy1)
{
  int k_copy1 = 0;
  int i_copy1 = 0;
  while (i_copy1 < n_copy1)
  {
    k_copy1 = k_copy1 + lib(m_copy1);
    i_copy1++;
  }

  return lib(5) + k_copy1;
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

