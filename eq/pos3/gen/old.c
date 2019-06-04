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

int client(int x, int x_1)
{
  if (x < 0)
  {
    return lib(x);
  }

  -x;
  if (x_1 < 0)
  {
    return lib(x);
  }

  return -x_1;
}

int main()
{
  int x;
  return client(x);
}

