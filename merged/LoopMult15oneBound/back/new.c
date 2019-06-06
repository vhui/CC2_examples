int lib(int x)
{
  if (x > 11)
    return 11;
  else
    return x - 1;

}

int clientmain(int x, int x_copy1)
{
  int ret = 0;
  if ((x >= 13) && (x < 16))
    ret = lib(x);

  ret;
  int ret_copy1;
  if ((x_copy1 < (-100)) || (x_copy1 > 100))
  {
    ret_copy1 = x_copy1;
  }
  else
  {
    if (x_copy1 > lib(x_copy1))
      ret_copy1 = x_copy1;
    else
      ret_copy1 = lib(x_copy1);

  }

  return ret + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

