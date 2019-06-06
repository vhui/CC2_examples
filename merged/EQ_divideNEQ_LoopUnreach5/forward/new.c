int lib(int x, int y)
{
  if (y == 0)
  {
    return 0;
  }

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
  int ret_copy1 = 0;
  if ((x_copy1 >= 5) && (x_copy1 < 7))
    ret_copy1 = lib(x_copy1, 5);

  return ret + ret_copy1;
}

int main()
{
  int a;
  int b;
  return client(a, b);
}

