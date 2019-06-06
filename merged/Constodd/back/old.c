int lib(int x)
{
  int counter = 0;
  while ((x % 2) == 0)
  {
    x = x / 2;
    counter++;
  }

  return counter;
}

int clientmain(void, int x_copy1)
{
  lib(5);
  int ret_copy1;
  if (lib(x_copy1) == 0)
  {
    ret_copy1 = 1;
  }
  else
  {
    ret_copy1 = 0;
  }

  return lib(5) + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

