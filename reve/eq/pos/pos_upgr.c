extern int __inlineCall(int);


int lib(int x) {
	if (x < 0){
		return -x;
	}else{
		return x;
	}
}

int client(int x){
  int ret;
	if (x > 0) {
		ret = -lib(-x);
	}else{
		ret = lib(x);
	}
  return ret;
}
