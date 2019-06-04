int lib(int x)
{
  return x % 6;
}

int client(int x, int x_1)
{
  if ((x < (-100)) || (x > 100))
  {
    return x;
  }

  x = (x * 5) * 6;
  if (lib(x) == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }

  if ((x_1 < (-100)) || (x_1 > 100))
  {
    return x_1;
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
  int x = -10;
  return client(x);
}

