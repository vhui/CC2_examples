int lib(int x)
{
  if (x < 0)
  {
    return -x;
  }

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
    if (x > lib(x))
      ret = x;
    else
      ret = lib(x);

  }

  ret;
  int ret_copy1 = -x_copy1;
  if (x_copy1 < 0)
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

