int foo(int a, int b);
int clientmain(void, int c_copy1, int d_copy1)
{
  foo(5, 900);
  int ret_copy1;
  if (d_copy1 == 0)
  {
    ret_copy1 = 0;
  }
  else
  {
    ret_copy1 = foo(c_copy1, d_copy1);
  }

  return foo(5, 900) + ret_copy1;
}

int foo(int a, int b)
{
  const int d = 3;
  int c = b + a;
  return c + d;
}

