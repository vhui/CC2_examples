int lib(int x)
{
  if (x < 0)
    return 0;
  else
    return x;

}

int client(int x, int x_copy1)
{
  int ret;
  if (x < 0)
  {
    ret = (-lib((-x) * 5)) / 5;
  }
  else
  {
    ret = (lib((x + 1) * 5) / 5) - 1;
  }

  ret;
  return ret + lib(2);
}

int main()
{
  int x;
  return client(x);
}

