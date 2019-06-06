int lib(int x)
{
  if (x > 10)
    return 11;
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
    if (x > lib(x))
      ret = x;
    else
      ret = lib(x);

  }

  ret;
  int ret_copy1;
  x_copy1 = (x_copy1 * 5) * 6;
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

