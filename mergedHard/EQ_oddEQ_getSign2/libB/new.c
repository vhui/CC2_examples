int lib(int x)
{
  if (x <= 0)
    return -1;
  else
    return 1;

}

int client(int x, int x_copy1)
{
  int ret;
  if (lib(x) == 0)
  {
    ret = 1;
  }
  else
  {
    ret = 0;
  }

  ret;
  int ret_copy1 = x_copy1;
  if (x_copy1 > 0)
  {
    ret_copy1 = lib(x_copy1);
  }

  return ret + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

