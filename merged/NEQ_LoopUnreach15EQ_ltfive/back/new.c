int lib(int x)
{
  if (x < 0)
    return 0;
  else
    return x;

}

int clientmain(int x, int x_copy1)
{
  int ret = 0;
  if ((x >= 13) && (x < 16))
    ret = lib(x);

  ret;
  int ret_copy1;
  if (x_copy1 < 0)
  {
    ret_copy1 = (-lib((-x_copy1) * 5)) / 5;
  }
  else
  {
    ret_copy1 = (lib((x_copy1 + 1) * 5) / 5) - 1;
  }

  return ret + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

