int foo(int a, int b);

int clientmain(int x) {
	if (x>=13 && x<16)
		return foo(x,15);
	return 0;
}

int foo(int a, int b) {
	int c=0;
	for (int i=1;i<=b;++i)
		c+=a;
	
	return c;
}
