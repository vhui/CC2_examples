int lib(int x)
{
  if (x <= 0)
    return -1;
  else
    return 1;

}

int client(unsigned int x, int x_copy1)
{
  int ret;
  if (x < 19)
  {
    ret = lib(20);
  }
  else
  {
    ret = lib(x);
  }

  return ret + lib(x_copy1);
}

int main()
{
  int x;
  return client(x);
}

