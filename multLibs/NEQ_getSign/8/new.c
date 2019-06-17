int lib(int x)
{
  if (x <= 0)
    return -1;
  else
    return 1;

}

int client(int x, int x_copy1, int x_copy2, int x_copy3, int x_copy4, int x_copy5, int x_copy6, int x_copy7)
{
  return ((((((lib(x) + lib(x_copy1)) + lib(x_copy2)) + lib(x_copy3)) + lib(x_copy4)) + lib(x_copy5)) + lib(x_copy6)) + lib(x_copy7);
}

int main()
{
  int x;
  return client(x);
}

