int lib(int x)
{
  if (x > 10)
    return 11;
  else
    return x;

}

int client(int x, int x_copy1, int x_copy2, int x_copy3)
{
  int ret;
  if (x > lib(x))
    ret = x;
  else
    ret = lib(x);

  int ret_copy1;
  if (x_copy1 > lib(x_copy1))
    ret_copy1 = x_copy1;
  else
    ret_copy1 = lib(x_copy1);

  int ret_copy2;
  if (x_copy2 > lib(x_copy2))
    ret_copy2 = x_copy2;
  else
    ret_copy2 = lib(x_copy2);

  int ret_copy3;
  if (x_copy3 > lib(x_copy3))
    ret_copy3 = x_copy3;
  else
    ret_copy3 = lib(x_copy3);

  return ((ret + ret_copy1) + ret_copy2) + ret_copy3;
}

int main()
{
  int x;
  return client(x);
}

