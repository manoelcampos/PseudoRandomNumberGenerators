#Required environment variables to use TestU01 C Library
#export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
#export LIBRARY_PATH=/usr/local/lib:$LIBRARY_PATH
#export C_INCLUDE_PATH=/usr/local/include:$C_INCLUDE_PATH

CC=gcc
CFLAGS=-Wall
#NEVER PUT THE FILE EXTENSION HERE
MAINFILE=task

all:
	mkdir -p bin
	$(CC) $(MAINFILE)1mylcg.c lib/lcglib.c lib/commonslib.c -lm -o bin/$(MAINFILE)1mylcg
	$(CC) $(MAINFILE)1mylcg_testu01.c lib/lcglib.c lib/commonslib.c -ltestu01 -lprobdist -lmylib -lm -o bin/$(MAINFILE)1testu01
	$(CC) $(MAINFILE)1native_rand_testu01.c -ltestu01 -lprobdist -lmylib -lm -o bin/$(MAINFILE)1native_rand_testu01
	$(CC) $(MAINFILE)2.c lib/betterlcglib.c lib/commonslib.c -lm -o bin/$(MAINFILE)2
	$(CC) $(MAINFILE)2testu01.c lib/betterlcglib.c lib/commonslib.c -ltestu01 -lprobdist -lmylib -lm -o bin/$(MAINFILE)2testu01
	$(CC) $(MAINFILE)3boxmuller.c lib/commonslib.c -lm -o bin/$(MAINFILE)3boxmuller
	$(CC) $(MAINFILE)3pollar_rejection.c lib/commonslib.c -lm -o bin/$(MAINFILE)3pollar_rejection
	$(CC) $(MAINFILE)4pareto.c lib/commonslib.c -lm -o bin/$(MAINFILE)4pareto

clean:
	#remove the files without extension (executables)
	cd bin && (rm -r `ls . | grep -v "\."`; cd ..)
	rm -rf doc

doc:
	doxygen Doxyfile.config