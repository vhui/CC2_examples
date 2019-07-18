int lib(int x)
{
  if (x > 10)
    return 11;
  else
    return x;

}

int clientmain()
{
  int x_copy1 = lib(5);
  int ret_copy1;
  if (x_copy1 > lib(x_copy1))
    ret_copy1 = x_copy1;
  else
    ret_copy1 = lib(x_copy1);

  return ret_copy1;
}

