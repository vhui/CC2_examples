int lib(int x, int y)
{
  return x / y;
}

int client(int c, int d, void)
{
  int ret;
  if (d == 0)
  {
    ret = 0;
  }
  else
  {
    ret = lib(c, d);
  }

  ret;
  return ret + lib(5, 900);
}

int main()
{
  int a;
  int b;
  return client(a, b);
}

