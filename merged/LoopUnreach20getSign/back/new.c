int lib(int x)
{
  if (x <= 0)
    return -1;
  else
    return 1;

}

int clientmain(int x, int x_copy1)
{
  int ret = 0;
  if ((x >= 18) && (x < 22))
    ret = lib(x);

  ret;
  return ret + lib(x_copy1);
}

int main()
{
  int x;
  return client(x);
}

