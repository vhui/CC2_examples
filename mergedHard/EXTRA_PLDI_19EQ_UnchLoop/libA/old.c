int client(unsigned int n, unsigned int m)
{
  int k = 0;
  int i = 0;
  while (i < n)
  {
    k = k + lib(m);
    i++;
  }

  return k + lib(5);
}

int lib(int a)
{
  int count = 0;
  int j = 0;
  while (j < a)
  {
    count++;
    j++;
  }

  return count;
}

