int lib(int x)
{
  return (x + 1) % 2;
}

int client(int x, unsigned int n_copy1, unsigned int m_copy1)
{
  int ret;
  if (lib(x) == 0)
  {
    ret = 1;
  }
  else
  {
    ret = 0;
  }

  int k_copy1 = 0;
  int i_copy1 = 0;
  while (i_copy1 < n_copy1)
  {
    k_copy1 = k_copy1 + lib(m_copy1);
    i_copy1++;
  }

  return ret + k_copy1;
}

