extern int __inlineCall(int);
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
        ret = 0;
        done = 1;
      }

    }

  }

  return ret;
}

int client(unsigned int x)
{
  int ret;
  if (x < 19)
  {
    ret = __inlineCall(lib(20, 1));
  }
  else
  {
    ret = __inlineCall(lib(x, 1));
  }

  int x_copy1 = ret;
  int ret_copy1;
  if (x_copy1 > 0)
  {
    ret_copy1 = -__inlineCall(lib(-x_copy1, -x_copy1));
  }
  else
  {
    ret_copy1 = __inlineCall(lib(x_copy1, x_copy1));
  }

  return ret_copy1;
}
