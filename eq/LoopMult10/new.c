int foo(int a, int b);

int clientmain(int x) {
	if (x>=9 && x<12)
		return foo(x,10);
	return 0;
}

int foo(int a, int b) {
	int c=0;
	for (int i=1;i<=a;++i)
		c+=b;
	
	return c;
}
