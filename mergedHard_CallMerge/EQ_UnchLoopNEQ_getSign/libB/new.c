int lib(int x)
{
  if (x <= 0)
    return -1;
  else
    return 1;

}

int clientmain()
{
  int x_copy1 = lib(5);
  return lib(x_copy1);
}

