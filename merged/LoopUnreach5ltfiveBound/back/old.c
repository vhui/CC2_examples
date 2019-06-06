int lib(int x)
{
  if (x < 5)
    return 5;
  else
    return x;

}

int clientmain(int x, int x_copy1)
{
  int ret = 0;
  if ((x >= 5) && (x < 7))
    ret = lib(x);

  ret;
  int ret_copy1;
  if ((x_copy1 < (-100)) || (x_copy1 > 100))
  {
    ret_copy1 = x_copy1;
  }
  else
  {
    if (x_copy1 < 0)
    {
      ret_copy1 = (-lib((-x_copy1) * 5)) / 5;
    }
    else
    {
      ret_copy1 = (lib((x_copy1 + 1) * 5) / 5) - 1;
    }

  }

  return ret + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

