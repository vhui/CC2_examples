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
    for (int i = 0; i < 8; i++)
    {
      int mod = x % primes[i];
      if (mod == 0)
        ret = x == primes[i];

    }

  }

  return ret;
}

int client(unsigned int x, unsigned int x_copy1, unsigned int x_copy2, unsigned int x_copy3, unsigned int x_copy4, unsigned int x_copy5, unsigned int x_copy6, unsigned int x_copy7, unsigned int x_copy8)
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

  int ret_copy1;
  if (x_copy1 < 19)
  {
    ret_copy1 = lib(20, 1);
  }
  else
  {
    ret_copy1 = lib(x_copy1, 1);
  }

  int ret_copy2;
  if (x_copy2 < 19)
  {
    ret_copy2 = lib(20, 1);
  }
  else
  {
    ret_copy2 = lib(x_copy2, 1);
  }

  int ret_copy3;
  if (x_copy3 < 19)
  {
    ret_copy3 = lib(20, 1);
  }
  else
  {
    ret_copy3 = lib(x_copy3, 1);
  }

  int ret_copy4;
  if (x_copy4 < 19)
  {
    ret_copy4 = lib(20, 1);
  }
  else
  {
    ret_copy4 = lib(x_copy4, 1);
  }

  int ret_copy5;
  if (x_copy5 < 19)
  {
    ret_copy5 = lib(20, 1);
  }
  else
  {
    ret_copy5 = lib(x_copy5, 1);
  }

  int ret_copy6;
  if (x_copy6 < 19)
  {
    ret_copy6 = lib(20, 1);
  }
  else
  {
    ret_copy6 = lib(x_copy6, 1);
  }

  int ret_copy7;
  if (x_copy7 < 19)
  {
    ret_copy7 = lib(20, 1);
  }
  else
  {
    ret_copy7 = lib(x_copy7, 1);
  }

  int ret_copy8;
  if (x_copy8 < 19)
  {
    ret_copy8 = lib(20, 1);
  }
  else
  {
    ret_copy8 = lib(x_copy8, 1);
  }

  return (((((((ret + ret_copy1) + ret_copy2) + ret_copy3) + ret_copy4) + ret_copy5) + ret_copy6) + ret_copy7) + ret_copy8;
}

int main()
{
  unsigned int x = 2;
  return client(x);
}

