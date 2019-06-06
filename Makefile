CILLY=cilly
CLANG=clang-6.0
KLEE=klee
COPTS=-Wno-attributes
INSTKLEE=/home/turingdreams/Documents/Research_UofT/klee/_build/instKlee.cma
# if instKlee has been installed, you can also use:
# INSTKLEE=instKlee

export CIL_FEATURES=cil.oneret

.PHONY: all clean

client_merged_g_0:client_merged_g_0.c
	$(CILLY) $(COPTS) --save-temps --noPrintLn -c --load=$(INSTKLEE) --doinstKlee --entry=clientmain   client_merged_g_0.c

clean:
	rm -rf *.o *.i *.cil.* klee-*
