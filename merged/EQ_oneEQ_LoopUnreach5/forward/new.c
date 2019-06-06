int lib(int x)
{
  if (x > 10)
    return 12;
  else
    return x + 1;

}

int client(int x, int x_copy1)
{
  int ret;
  if (x > lib(x))
    ret = x;
  else
    ret = lib(x);

  ret;
  int ret_copy1 = 0;
  if ((x_copy1 >= 5) && (x_copy1 < 7))
    ret_copy1 = lib(x_copy1);

  return ret + ret_copy1;
}

int main()
{
  int x;
  return client(x);
}

