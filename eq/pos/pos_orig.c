
int lib(int x) {
	int counter = 0;
	while (x < 0) {
		x++;
		counter++;
	}
	return counter;
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


int main() {
	int x;//=3089104896;
	return client(x);
}
