int lib(int x)
{
  return (x + 1) % 2;
}

int clientmain(int x, int x_copy1)
{
  lib(2);
  int ret_copy1;
  if (lib(x_copy1) == 0)
  {
    ret_copy1 = 1;
  }
  else
  {
    ret_copy1 = 0;
  }

  return lib(2) + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

