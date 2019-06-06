int lib(int x)
{
  if (x == 0)
    return 0;

  if (x < 0)
    return -1;
  else
    return 1;

}

int client(int x, int x_copy1)
{
  lib(x);
  return lib(x) + lib(2);
}

int main()
{
  int x;
  return client(x);
}

