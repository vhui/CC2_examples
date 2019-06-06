int lib(int x)
{
  if (x < 0)
  {
    return -x;
  }

  return x;
}

int client(int x, unsigned int x_copy1)
{
  int ret = -x;
  if (x < 0)
  {
    ret = lib(x);
  }

  ret;
  return ret + lib(x_copy1);
}

int main()
{
  int x;
  return client(x);
}

