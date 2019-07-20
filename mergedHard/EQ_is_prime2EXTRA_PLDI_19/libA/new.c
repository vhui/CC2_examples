int lib(unsigned int x, int b)
{
  int ret = 1;
  unsigned int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
  if (b == 0)
  {
    ret = 0;
  }
  else
  {
    int done = 0;
    for (int i = 0; i < 8; i++)
    {
      int mod = x % primes[i];
      if ((!done) && (mod == 0))
      {
        ret = x == primes[i];
        done = 1;
      }

    }

  }

  return ret;
}

int client(unsigned int x, unsigned int n_copy1, unsigned int m_copy1)
{
  int ret;
  if (x < 19)
  {
    ret = lib(20, 1);
  }
  else
  {
    ret = lib(x, 1);
  }

  int k_copy1 = 0;
  int i_copy1 = 0;
  while (i_copy1 < n_copy1)
  {
    k_copy1 = k_copy1 + lib(m_copy1, m_copy1);
    i_copy1++;
  }

  return ret + k_copy1;
}

