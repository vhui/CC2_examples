int foo(int a, int b);
int clientmain(int x_copy1)
{
  foo(5, 900);
  int ret_copy1 = 0;
  if ((x_copy1 >= 13) && (x_copy1 < 16))
    ret_copy1 = foo(x_copy1, 15);

  return foo(5, 900) + ret_copy1;
}

int foo(int a, int b)
{
  int c = b + a;
  return c;
}

