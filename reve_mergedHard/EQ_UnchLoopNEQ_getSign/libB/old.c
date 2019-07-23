extern int __inlineCall(int);
int lib(int x)
{
  if (x == 0)
    return 0;

  if (x < 0)
    return -1;
  else
    return 1;

}

int clientmain(int x_copy1)
{
  return __inlineCall(lib(5)) + __inlineCall(lib(x_copy1));
}

