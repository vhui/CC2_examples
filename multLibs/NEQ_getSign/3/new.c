int lib(int x)
{
  if (x <= 0)
    return -1;
  else
    return 1;

}

int client(int x, int x_copy1, int x_copy2)
{
  return (lib(x) + lib(x_copy1)) + lib(x_copy2);
}

int main()
{
  int x;
  return client(x);
}

