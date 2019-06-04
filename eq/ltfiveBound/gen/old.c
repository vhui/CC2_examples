int lib(int x)
{
  if (x < 5)
    return 5;
  else
    return x;

}

int client(int x, int x_1)
{
  if ((x < (-100)) || (x > 100))
  {
    return x;
  }

  if (x < 0)
  {
    return (-lib((-x) * 5)) / 5;
  }
  else
  {
    return (lib((x + 1) * 5) / 5) - 1;
  }

  if ((x_1 < (-100)) || (x_1 > 100))
  {
    return x_1;
  }

  if (x_1 < 0)
  {
    return (-lib((-x) * 5)) / 5;
  }
  else
  {
    return (lib((x + 1) * 5) / 5) - 1;
  }

}

int main()
{
  int x;
  return client(x);
}

