int lib(int x)
{
  int ret;
  if (x > 11)
    ret = 11;
  else
    ret = x - 1;

  return ret;
}

int client(int x, int x_copy1, int x_copy2)
{
  int ret;
  if (x > lib(x))
    ret = x;
  else
    ret = lib(x);

  int ret_copy1;
  if (x_copy1 > lib(x_copy1))
    ret_copy1 = x_copy1;
  else
    ret_copy1 = lib(x_copy1);

  int ret_copy2;
  if (x_copy2 > lib(x_copy2))
    ret_copy2 = x_copy2;
  else
    ret_copy2 = lib(x_copy2);

  return (ret + ret_copy1) + ret_copy2;
}

int main()
{
  int x;
  return client(x);
}

