int lib(int x)
{
  if (x < 0)
  {
    return -x;
  }

  int counter = 0;
  while (x > 0)
  {
    x += 1;
    counter += 1;
  }

  return counter;
}

int client(int x, int x_copy1)
{
  int ret = -x;
  if (x < 0)
  {
    ret = lib(x);
  }

  ret;
  int ret_copy1;
  x_copy1 = (x_copy1 * 5) * 6;
  if (lib(x_copy1) == 0)
  {
    ret_copy1 = 1;
  }
  else
  {
    ret_copy1 = 0;
  }

  return ret + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

