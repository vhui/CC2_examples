int lib(int x, int y)
{
  return x / y;
}

int client(int x, int c_copy1, int d_copy1)
{
  int ret;
  if (lib(x, x) == 0)
  {
    ret = 1;
  }
  else
  {
    ret = 0;
  }

  ret;
  int ret_copy1;
  if (d_copy1 == 0)
  {
    ret_copy1 = 0;
  }
  else
  {
    ret_copy1 = lib(c_copy1, d_copy1);
  }

  return ret + ret_copy1;
}

int main()
{
  int a;
  int b;
  return client(a, b);
}

