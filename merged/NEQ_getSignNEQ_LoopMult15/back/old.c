int foo(int a, int b);
int client(int x, int x_copy1)
{
  foo(x, x);
  int ret_copy1 = 0;
  if ((x_copy1 >= 13) && (x_copy1 < 16))
    ret_copy1 = foo(x_copy1, 15);

  return foo(x, x) + ret_copy1;
}

int foo(int a, int b)
{
  int c = 0;
  for (int i = 1; i <= b; ++i)
    c -= a;

  return c;
}

