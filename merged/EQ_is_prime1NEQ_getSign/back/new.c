int lib(int x)
{
  if (x <= 0)
    return -1;
  else
    return 1;

}

int client(unsigned int x, int x_copy1)
{
  lib(x);
  return lib(x) + lib(x_copy1);
}

int main()
{
  int x;
  return client(x);
}

