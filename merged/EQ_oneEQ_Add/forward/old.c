int lib(int x)
{
  if (x > 10)
    return 11;
  else
    return x;

}

int client(int x, void)
{
  int ret;
  if (x > lib(x))
    ret = x;
  else
    ret = lib(x);

  ret;
  return ret + lib(5);
}

int main()
{
  int x;
  return client(x);
}

