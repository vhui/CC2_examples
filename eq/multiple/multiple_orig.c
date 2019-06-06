int lib(int x) {
	return x % 5;
}

int client(int x){
  int ret;
	x = x*5*6;
	if (lib(x)==0){
		ret = 1;
	}else{
		ret = 0;
	}
  return ret;
}

int main() {
	int x;// =3918991416;
	return client(x);
}
