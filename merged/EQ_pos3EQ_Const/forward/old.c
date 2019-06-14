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

int client(int x)
{
  int ret = -x;
  if (x < 0)
  {
    ret = lib(x);
  }

  ret;
  return ret + lib(5);
}

int main()
{
  int x;
  return client(x);
}

