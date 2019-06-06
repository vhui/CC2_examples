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
  if ((x < (-100)) || (x > 100))
  {
    ret = x;
  }
  else
  {
    x = (x * 5) * 6;
    if (lib(x) == 0)
    {
      ret = 1;
    }
    else
    {
      ret = 0;
    }

  }

  ret;
  int ret_copy1;
  if (x_copy1 > lib(x_copy1))
    ret_copy1 = x_copy1;
  else
    ret_copy1 = lib(x_copy1);

  return ret + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

