int lib(int x) {
	int counter = 0;
	while (x % 2 == 0){
		x = x/2;
		counter++;
	}
	return counter;
}

int client(int x){
  int ret;
	if (lib(x)==0){
	   	ret = 1;
	}else{
		ret = 0;
	}
  return ret;
}

int main() {
	int x;
	return client(x);
}
