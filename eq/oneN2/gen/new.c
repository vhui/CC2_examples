int lib(int x)
{
  if (x > 11)
    return 11;
  else
    return x - 1;

}

int client(int x, int x_1)
{
  if (x > lib(x))
    return x;
  else
    return lib(x);

  if (x_1 > lib(x))
    return x_1;
  else
    return lib(x);

}

int main()
{
  int x;
  return client(x);
}

