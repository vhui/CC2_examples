int client(int x)
{
  int INLINED_RET_1;
  int INLINED_RET_0;
  int ret;
  if (x > 0)
  {
    INLINED_RET_0 = foo(5, 900);
    ret = -INLINED_RET_0;
  }
  else
  {
    INLINED_RET_1 = foo(5, 900);
    ret = INLINED_RET_1;
  }

  return ret;
}

int foo(int a, int b)
{
  int c = b + a;
  return c;
}


