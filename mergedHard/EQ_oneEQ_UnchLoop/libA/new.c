int lib(int x)
{
  if (x > 10)
    return 12;
  else
    return x + 1;

}

int client(int x)
{
  int ret;
  if (x > lib(x))
    ret = x;
  else
    ret = lib(x);

  return ret + lib(5);
}

int main()
{
  int x;
  return client(x);
}

