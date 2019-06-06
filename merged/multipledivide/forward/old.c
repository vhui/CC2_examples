int lib(int x)
{
  return x % 5;
}

int client(int x, int c_copy1, int d_copy1)
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
  if (d_copy1 == 0)
  {
    ret_copy1 = 0;
  }
  else
  {
    ret_copy1 = lib(c_copy1);
  }

  return ret + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

