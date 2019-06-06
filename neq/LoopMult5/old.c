int foo(int a, int b);

int clientmain(int x) {
  int ret = 0;
	if (x>=5 && x<7)
		ret = foo(x,5);
	return ret;
}

int foo(int a, int b) {
	int c=0;
	for (int i=1;i<=b;++i)
		c-=a;
	
	return c;
}
