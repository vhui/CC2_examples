int lib(int x)
{
  if (x < 0)
  {
    return -x;
  }

  return x;
}

int client(int x, int x_copy1)
{
  int ret = -x;
  if (x < 0)
  {
    ret = lib(x);
  }

  ret;
  int ret_copy1 = 0;
  if ((x_copy1 >= 13) && (x_copy1 < 16))
    ret_copy1 = lib(x_copy1);

  return ret + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

