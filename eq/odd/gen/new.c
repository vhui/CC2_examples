int lib(int x)
{
  return (x + 1) % 2;
}

int client(int x, int x_1)
{
  if (lib(x) == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }

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

