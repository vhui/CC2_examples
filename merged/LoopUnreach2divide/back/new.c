int lib(int x, int y)
{
  if (y == 0)
  {
    return 0;
  }

  return x / y;
}

int clientmain(int x, int c_copy1, int d_copy1)
{
  lib(2, 2);
  int ret_copy1;
  if (d_copy1 == 0)
  {
    ret_copy1 = 0;
  }
  else
  {
    ret_copy1 = lib(c_copy1, d_copy1);
  }

  return lib(2, 2) + ret_copy1;
}

int main()
{
  int a;
  int b;
  return client(a, b);
}

