int lib(int x)
{
  if (x < 0)
  {
    return -x;
  }

  return x;
}

int client(int x, void)
{
  int ret = -x;
  if (x < 0)
  {
    ret = lib(x);
  }

  ret;
  return ret + lib(5);
}

int main()
{
  int x;
  return client(x);
}

