int lib(int x)
{
  if (x > 10)
    return 11;
  else
    return x;

}

int client(int x, unsigned int x_copy1)
{
  int ret;
  if (x > lib(x))
    ret = x;
  else
    ret = lib(x);

  int ret_copy1;
  if (x_copy1 < 19)
  {
    ret_copy1 = lib(20);
  }
  else
  {
    ret_copy1 = lib(x_copy1);
  }

  return ret + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}
