int lib(int x)
{
  if (x > 10)
    return 11;
  else
    return x;

}

int client(int x, int x_1)
{
  if ((x < (-100)) || (x > 100))
  {
    return x;
  }

  if (x > lib(x))
    return x;
  else
    return lib(x);

  if ((x_1 < (-100)) || (x_1 > 100))
  {
    return x_1;
  }

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

