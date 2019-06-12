CILLY=cilly
CLANG=clang-6.0
KLEE=klee
COPTS=-Wno-attributes
INSTKLEE=/home/turingdreams/Documents/Research_UofT/klee/_build/instKlee.cma
# if instKlee has been installed, you can also use:
# INSTKLEE=instKlee

export CIL_FEATURES=cil.oneret

.PHONY: all clean

merged_g_0:merged_g_0.c
	$(CILLY) $(COPTS) --save-temps --noPrintLn -c --load=$(INSTKLEE) --doinstKlee --entry=lib  --assume='x == '128' & x_copy1 == '0'' merged_g_0.c

clean:
	rm -rf *.o *.i *.cil.* klee-*
