/*
 * Yi's example in klee
 */

int lib(int x){
	if (x > 10)
		return 11;
	else
		return x;
}

int client(int x){
  int ret;
	if (x > lib(x))
		ret = x;
	else
		ret = lib(x);
  return ret;
}
