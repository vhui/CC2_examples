int lib(int x, int y)
{
  if (y == 0)
  {
    return 0;
  }

  return x / y;
}

int client(int c, int d, int c_copy1, int d_copy1, int c_copy2, int d_copy2, int c_copy3, int d_copy3, int c_copy4, int d_copy4, int c_copy5, int d_copy5, int c_copy6, int d_copy6, int c_copy7, int d_copy7, int c_copy8, int d_copy8, int c_copy9, int d_copy9, int c_copy10, int d_copy10, int c_copy11, int d_copy11, int c_copy12, int d_copy12, int c_copy13, int d_copy13, int c_copy14, int d_copy14)
{
  int ret;
  if (d == 0)
  {
    ret = 0;
  }
  else
  {
    ret = lib(c, d);
  }

  int ret_copy1;
  if (d_copy1 == 0)
  {
    ret_copy1 = 0;
  }
  else
  {
    ret_copy1 = lib(c_copy1, d_copy1);
  }

  int ret_copy2;
  if (d_copy2 == 0)
  {
    ret_copy2 = 0;
  }
  else
  {
    ret_copy2 = lib(c_copy2, d_copy2);
  }

  int ret_copy3;
  if (d_copy3 == 0)
  {
    ret_copy3 = 0;
  }
  else
  {
    ret_copy3 = lib(c_copy3, d_copy3);
  }

  int ret_copy4;
  if (d_copy4 == 0)
  {
    ret_copy4 = 0;
  }
  else
  {
    ret_copy4 = lib(c_copy4, d_copy4);
  }

  int ret_copy5;
  if (d_copy5 == 0)
  {
    ret_copy5 = 0;
  }
  else
  {
    ret_copy5 = lib(c_copy5, d_copy5);
  }

  int ret_copy6;
  if (d_copy6 == 0)
  {
    ret_copy6 = 0;
  }
  else
  {
    ret_copy6 = lib(c_copy6, d_copy6);
  }

  int ret_copy7;
  if (d_copy7 == 0)
  {
    ret_copy7 = 0;
  }
  else
  {
    ret_copy7 = lib(c_copy7, d_copy7);
  }

  int ret_copy8;
  if (d_copy8 == 0)
  {
    ret_copy8 = 0;
  }
  else
  {
    ret_copy8 = lib(c_copy8, d_copy8);
  }

  int ret_copy9;
  if (d_copy9 == 0)
  {
    ret_copy9 = 0;
  }
  else
  {
    ret_copy9 = lib(c_copy9, d_copy9);
  }

  int ret_copy10;
  if (d_copy10 == 0)
  {
    ret_copy10 = 0;
  }
  else
  {
    ret_copy10 = lib(c_copy10, d_copy10);
  }

  int ret_copy11;
  if (d_copy11 == 0)
  {
    ret_copy11 = 0;
  }
  else
  {
    ret_copy11 = lib(c_copy11, d_copy11);
  }

  int ret_copy12;
  if (d_copy12 == 0)
  {
    ret_copy12 = 0;
  }
  else
  {
    ret_copy12 = lib(c_copy12, d_copy12);
  }

  int ret_copy13;
  if (d_copy13 == 0)
  {
    ret_copy13 = 0;
  }
  else
  {
    ret_copy13 = lib(c_copy13, d_copy13);
  }

  int ret_copy14;
  if (d_copy14 == 0)
  {
    ret_copy14 = 0;
  }
  else
  {
    ret_copy14 = lib(c_copy14, d_copy14);
  }

  return (((((((((((((ret + ret_copy1) + ret_copy2) + ret_copy3) + ret_copy4) + ret_copy5) + ret_copy6) + ret_copy7) + ret_copy8) + ret_copy9) + ret_copy10) + ret_copy11) + ret_copy12) + ret_copy13) + ret_copy14;
}

int main()
{
  int a;
  int b;
  return client(a, b);
}

