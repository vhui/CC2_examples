extern int __inlineCall(int);

int lib(int x) {
  if (x == 0)
     return 0;
  if (x < 0)
     return -1;
  else
     return 1;
}

int client(int x){
  int ret = x;
  if (x > 0) {
    ret = lib(x);
  }
  return ret;
}
