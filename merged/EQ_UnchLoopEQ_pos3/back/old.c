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

int clientmain(void, int x_copy1)
{
  lib(5);
  int ret_copy1 = -x_copy1;
  if (x_copy1 < 0)
  {
    ret_copy1 = lib(x_copy1);
  }

  return lib(5) + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

