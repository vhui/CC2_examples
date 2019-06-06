int lib(int x) {
	if (x < 5)
		return 5;
	else
		return x;
}

int client(int x){
  int ret;
	if (x < 0){
		ret = -lib((-x)*5)/5;
	}else{
		ret = lib((x+1)*5)/5 - 1;
	}
  return ret;
}

int main() {
	int x;//=2147483648;
	return client(x);
}
