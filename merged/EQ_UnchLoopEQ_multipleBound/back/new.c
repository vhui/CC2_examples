int lib(int x)
{
  return x % 6;
}

int clientmain(void, int x_copy1)
{
  lib(5);
  int ret_copy1;
  if ((x_copy1 < (-100)) || (x_copy1 > 100))
  {
    ret_copy1 = x_copy1;
  }
  else
  {
    x_copy1 = (x_copy1 * 5) * 6;
    if (lib(x_copy1) == 0)
    {
      ret_copy1 = 1;
    }
    else
    {
      ret_copy1 = 0;
    }

  }

  return lib(5) + ret_copy1;
}

int main()
{
  int x = -10;
  return client(x);
}

