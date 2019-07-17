int lib(int x) {
	if (x < 0){
		return -x;
	}
	return x;
}

int client(int x){
  int ret = -x;
	if (x < 0) {
		ret = lib(x);
	}
  return ret;
}

