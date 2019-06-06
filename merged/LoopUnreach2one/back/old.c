int lib(int x)
{
  if (x > 10)
    return 11;
  else
    return x;

}

int clientmain(int x, int x_copy1)
{
  lib(2);
  int ret_copy1;
  if (x_copy1 > lib(x_copy1))
    ret_copy1 = x_copy1;
  else
    ret_copy1 = lib(x_copy1);

  return lib(2) + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

