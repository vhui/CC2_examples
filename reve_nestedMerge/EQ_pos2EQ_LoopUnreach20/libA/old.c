int client(int x)
{
  int INLINED_RET_0;
  int INLINED_RET_1;
  int ret;
  if (x > 0)
  {
    int x_copy0 = -x;
    int ret_copy0 = 0;
    if ((x_copy0 >= 18) && (x_copy0 < 22))
    {
      ret_copy0 = __inlineCall(foo(x_copy0, 20));
    }

    INLINED_RET_0 = ret_copy0;
    ret = -__inlineCall(INLINED_RET_0);
  }
  else
  {
    int x_copy1 = x;
    int ret_copy1 = 0;
    if ((x_copy1 >= 18) && (x_copy1 < 22))
    {
      ret_copy1 = __inlineCall(foo(x_copy1, 20));
    }

    INLINED_RET_1 = ret_copy1;
    ret = __inlineCall(INLINED_RET_1);
  }

  return ret;
}

int foo(int a, int b)
{
  int c = 0;
  if (a < 0)
  {
    for (int i = 1; i <= b; ++i)
      c += a;

  }

  return c;
}


