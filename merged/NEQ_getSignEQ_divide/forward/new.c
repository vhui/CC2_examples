int lib(int x)
{
  if (x <= 0)
    return -1;
  else
    return 1;

}

int client(int x, int c_copy1, int d_copy1)
{
  lib(x);
  int ret_copy1;
  if (d_copy1 == 0)
  {
    ret_copy1 = 0;
  }
  else
  {
    ret_copy1 = lib(c_copy1);
  }

  return lib(x) + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

