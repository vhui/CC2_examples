int lib(int x)
{
  if (x <= 0)
    return -1;
  else
    return 1;

}

int clientmain(int x_copy1)
{
  return lib(5) + lib(x_copy1);
}

int main()
{
  int x;
  return client(x);
}

