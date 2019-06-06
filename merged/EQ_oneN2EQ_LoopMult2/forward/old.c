int lib(int x)
{
  int ret;
  if (x > 10)
    ret = 11;
  else
    ret = x;

  return ret;
}

int client(int x, int x_copy1)
{
  int ret;
  if (x > lib(x))
    ret = x;
  else
    ret = lib(x);

  ret;
  return ret + lib(2);
}

int main()
{
  int x;
  return client(x);
}

