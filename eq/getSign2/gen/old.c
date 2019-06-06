int lib(int x)
{
  if (x == 0)
    return 0;

  if (x < 0)
    return -1;
  else
    return 1;

}

int client(int x, int x_copy1)
{
  int ret = x;
  if (x > 0)
  {
    ret = lib(x);
  }

  ret;
  int ret_copy1 = x_copy1;
  if (x_copy1 > 0)
  {
    ret_copy1 = lib(x_copy1);
  }

  return ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

