int lib(int x)
{
  return x % 6;
}

int client(int x, int x_copy1)
{
  lib(x);
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

  return lib(x) + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

