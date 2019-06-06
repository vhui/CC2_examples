int lib(int x, int y)
{
  return x / y;
}

int client(int c, int d, int x_copy1)
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
  return ret + lib(x_copy1, x_copy1);
}

int main()
{
  int a;
  int b;
  return client(a, b);
}

