int foo(int a, int b);

int clientmain(void) {
	return foo(5,900);
}

int foo(int a, int b) {
	int c=b+a;
	return c;
}
