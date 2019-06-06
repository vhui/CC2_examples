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
  int ret_copy1;
  x_copy1 = (x_copy1 * 5) * 6;
  if (lib(x_copy1) == 0)
  {
    ret_copy1 = 1;
  }
  else
  {
    ret_copy1 = 0;
  }

  return ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

