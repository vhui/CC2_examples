int lib(int x)
{
  if (x < 0)
    return 0;
  else
    return x;

}

int client(int x, int x_copy1)
{
  int ret;
  if ((x < (-100)) || (x > 100))
  {
    ret = x;
  }
  else
  {
    if (x < 0)
    {
      ret = (-lib((-x) * 5)) / 5;
    }
    else
    {
      ret = (lib((x + 1) * 5) / 5) - 1;
    }

  }

  ret;
  int ret_copy1 = 0;
  if ((x_copy1 >= 9) && (x_copy1 < 12))
    ret_copy1 = lib(x_copy1);

  return ret + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

