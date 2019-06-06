int lib(int x)
{
  if (x == 0)
    return 0;

  if (x < 0)
    return -1;
  else
    return 1;

}

int clientmain(int x, int x_copy1)
{
  lib(2);
  return lib(2) + lib(x_copy1);
}

int main()
{
  int x;
  return client(x);
}

