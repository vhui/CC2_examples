int lib(int x, int y)
{
  return x / y;
}

int client(int c, int d, int c_1, int d_1)
{
  if (d == 0)
  {
    return 0;
  }

  lib(c, d);
  if (d_1 == 0)
  {
    return 0;
  }

  return lib(c, d);
}

int main()
{
  int a;
  int b;
  return client(a, b);
}

