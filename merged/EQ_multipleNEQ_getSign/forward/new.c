int lib(int x)
{
  return x % 6;
}

int client(int x, int x_copy1)
{
  int ret;
  x = (x * 5) * 6;
  if (lib(x) == 0)
  {
    ret = 1;
  }
  else
  {
    ret = 0;
  }

  ret;
  return ret + lib(x_copy1);
}

int main()
{
  int x;
  return client(x);
}

