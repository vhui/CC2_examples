int foo(int a, int b);

int clientmain(int x) {
	return foo(2,2);
}

int foo(int a, int b) {
	int c=0;
	for (int i=1;i<=b;++i)
		c-=a;
	
	return c;
}
