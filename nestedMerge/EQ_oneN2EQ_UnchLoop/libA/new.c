int foo(int a, int b)
{
  int c = 0;
  for (int i = 0; i < a; ++i)
  {
    c = c + b;
  }

  return c + 1;
}

int client(int x)
{
  int INLINED_RET_0;
  int INLINED_RET_1;
  int ret;
  INLINED_RET_0 = foo(5, 900);
  if (x > INLINED_RET_0)
  {
    ret = x;
  }
  else
  {
    INLINED_RET_1 = foo(5, 900);
    ret = INLINED_RET_1;
  }

  return ret;
}


