int lib(int x)
{
  int ret;
  if (x > 11)
    ret = 11;
  else
    ret = x - 1;

  return ret;
}

int client(int x, unsigned int x_copy1)
{
  int ret;
  if (x > lib(x))
    ret = x;
  else
    ret = lib(x);

  ret;
  return ret + lib(x_copy1);
}

int main()
{
  int x;
  return client(x);
}

