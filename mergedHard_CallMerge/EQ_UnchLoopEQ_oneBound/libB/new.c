int lib(int x)
{
  if (x > 11)
    return 11;
  else
    return x - 1;

}

int clientmain()
{
  int x_copy1 = lib(5);
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

  return ret_copy1;
}

