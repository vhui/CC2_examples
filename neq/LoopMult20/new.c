int foo(int a, int b);

int clientmain(int x) {
	if (x>=18 && x<22)
		return foo(x,20);
	return 0;
}

int foo(int a, int b) {
	int c=0;
	for (int i=1;i<=a;++i)
		c+=b;
	
	return c;
}
