int lib(int x)
{
  if (x <= 0)
    return -1;
  else
    return 1;

}

int client(int c, int d, int x_copy1)
{
  int ret;
  if (d == 0)
  {
    ret = 0;
  }
  else
  {
    ret = lib(c);
  }

  ret;
  return ret + lib(x_copy1);
}

int main()
{
  int x;
  return client(x);
}

