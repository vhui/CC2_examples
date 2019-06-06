int lib(int x)
{
  if (x <= 0)
    return -1;
  else
    return 1;

}

int clientmain(void, int x_copy1)
{
  lib(5);
  return lib(5) + lib(x_copy1);
}

int main()
{
  int x;
  return client(x);
}

