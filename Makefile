CILLY=cilly
CLANG=clang-6.0
KLEE=klee
COPTS=-Wno-attributes
INSTKLEE=/home/turingdreams/Documents/Research_UofT/klee/_build/instKlee.cma
# if instKlee has been installed, you can also use:
# INSTKLEE=instKlee

export CIL_FEATURES=cil.oneret

.PHONY: all clean

merged_g:merged_g.c
	$(CILLY) $(COPTS) --save-temps --noPrintLn -c --load=$(INSTKLEE) --doinstKlee --entry=lib  --assume='x == '9569406'' merged_g.c

clean:
	rm -rf *.o *.i *.cil.* klee-*
