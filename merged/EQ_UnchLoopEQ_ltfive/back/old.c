int lib(int x)
{
  if (x < 5)
    return 5;
  else
    return x;

}

int clientmain(void, int x_copy1)
{
  lib(5);
  int ret_copy1;
  if (x_copy1 < 0)
  {
    ret_copy1 = (-lib((-x_copy1) * 5)) / 5;
  }
  else
  {
    ret_copy1 = (lib((x_copy1 + 1) * 5) / 5) - 1;
  }

  return lib(5) + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

