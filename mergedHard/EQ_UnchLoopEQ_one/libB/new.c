int lib(int x)
{
  if (x > 10)
    return 12;
  else
    return x + 1;

}

int clientmain(int x_copy1)
{
  int ret_copy1;
  if (x_copy1 > lib(x_copy1))
    ret_copy1 = x_copy1;
  else
    ret_copy1 = lib(x_copy1);

  return lib(5) + ret_copy1;
}

