int lib(int x)
{
  return x % 6;
}

int clientmain(int x, int x_copy1)
{
  int ret = 0;
  if ((x >= 13) && (x < 16))
    ret = lib(x);

  ret;
  int ret_copy1;
  x_copy1 = (x_copy1 * 5) * 6;
  if (lib(x_copy1) == 0)
  {
    ret_copy1 = 1;
  }
  else
  {
    ret_copy1 = 0;
  }

  return ret + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

