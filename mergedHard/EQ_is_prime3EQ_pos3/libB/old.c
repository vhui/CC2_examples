int lib(int x)
{
  int ret;
  if (x < 0)
  {
    ret = -x;
  }
  else
  {
    int counter = 0;
    while (x > 0)
    {
      x += 1;
      counter += 1;
    }

    ret = counter;
  }

  return ret;
}

int client(unsigned int x, int x_copy1)
{
  int ret;
  unsigned int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
  int done = 0;
  for (int i = 0; i < 8; i++)
  {
    if ((!done) && (x == primes[i]))
    {
      ret = 1;
      done = 1;
    }

  }

  if (!done)
    ret = lib(x);

  int ret_copy1 = -x_copy1;
  if (x_copy1 < 0)
  {
    ret_copy1 = lib(x_copy1);
  }

  return ret + ret_copy1;
}

