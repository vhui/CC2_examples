int lib(int x)
{
  return x % 5;
}

int client(int x, void)
{
  int ret;
  if ((x < (-100)) || (x > 100))
  {
    ret = x;
  }
  else
  {
    x = (x * 5) * 6;
    if (lib(x) == 0)
    {
      ret = 1;
    }
    else
    {
      ret = 0;
    }

  }

  ret;
  return ret + lib(5);
}

int main()
{
  int x = -10;
  return client(x);
}

