int foo(int a, int b);
int clientmain(int c_copy1, int d_copy1)
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
  int c = a + b;
  return c + 3;
}

