int lib(int x)
{
  return x % 6;
}

int client(int x, int x_1)
{
  x = (x * 5) * 6;
  if (lib(x) == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }

  x_1 = (x_1 * 5) * 6;
  if (lib(x) == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }

}

int main()
{
  int x;
  return client(x);
}

