int lib(int x, int y)
{
  return x / y;
}

int clientmain(void, int c_copy1, int d_copy1)
{
  lib(5, 900);
  int ret_copy1;
  if (d_copy1 == 0)
  {
    ret_copy1 = 0;
  }
  else
  {
    ret_copy1 = lib(c_copy1, d_copy1);
  }

  return lib(5, 900) + ret_copy1;
}

int main()
{
  int a;
  int b;
  return client(a, b);
}

