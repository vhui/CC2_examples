int lib(int x)
{
  if (x < 0)
  {
    return -x;
  }

  return x;
}

int client(unsigned int x, int x_copy1)
{
  lib(x);
  int ret_copy1 = -x_copy1;
  if (x_copy1 < 0)
  {
    ret_copy1 = lib(x_copy1);
  }

  return lib(x) + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}
