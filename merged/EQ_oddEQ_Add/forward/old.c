int lib(int x)
{
  int counter = 0;
  while ((x % 2) == 0)
  {
    x = x / 2;
    counter++;
  }

  return counter;
}

int client(int x, void)
{
  int ret;
  if (lib(x) == 0)
  {
    ret = 1;
  }
  else
  {
    ret = 0;
  }

  ret;
  return ret + lib(5);
}

int main()
{
  int x;
  return client(x);
}

