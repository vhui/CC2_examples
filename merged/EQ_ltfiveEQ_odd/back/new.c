int lib(int x)
{
  return (x + 1) % 2;
}

int client(int x, int x_copy1)
{
  int ret;
  if (x < 0)
  {
    ret = (-lib((-x) * 5)) / 5;
  }
  else
  {
    ret = (lib((x + 1) * 5) / 5) - 1;
  }

  ret;
  int ret_copy1;
  if (lib(x_copy1) == 0)
  {
    ret_copy1 = 1;
  }
  else
  {
    ret_copy1 = 0;
  }

  return ret + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

