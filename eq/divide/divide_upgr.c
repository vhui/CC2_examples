int lib(int x, int y) {
  if (y == 0) {
    return 0;
  }
  return x / y;
}

int client(int c, int d) {
  int ret;
  if (d == 0) {
    ret = 0;
  } else { ret = lib(c, d);
  }
  return ret;
}

int main() {
  int a;
  int b;
  return client(a, b);
}
