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

int client(int x)
{
  int ret = -x;
  if (x < 0)
  {
    ret = lib(x);
  }

  unsigned int x_copy1 = ret;
  return lib(x_copy1);
}

