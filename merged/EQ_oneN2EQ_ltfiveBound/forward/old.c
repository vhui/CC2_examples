int lib(int x)
{
  int ret;
  if (x > 10)
    ret = 11;
  else
    ret = x;

  return ret;
}

int client(int x, int x_copy1)
{
  int ret;
  if (x > lib(x))
    ret = x;
  else
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

