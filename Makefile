CILLY=cilly
CLANG=clang-6.0
KLEE=klee
COPTS=-Wno-attributes
INSTKLEE=/usr/local/lib/python3.5/dist-packages/CC2-0.1-py3.5.egg/CC2/_build/instKlee.cma
# if instKlee has been installed, you can also use:
# INSTKLEE=instKlee

export CIL_FEATURES=cil.oneret

.PHONY: all clean

merged_g_0:merged_g_0.c
	$(CILLY) $(COPTS) --save-temps --noPrintLn -c --load=$(INSTKLEE) --doinstKlee --entry=lib  --assume='ret == '0' & x == '-2147483648'' merged_g_0.c

clean:
	rm -rf *.o *.i *.cil.* klee-*
