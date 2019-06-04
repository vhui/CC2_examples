int lib(int x)
{
  int counter = 0;
  while ((x % 2) == 0)
  {
    x = x / 2;
    counter++;
  }

  return counter;
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

