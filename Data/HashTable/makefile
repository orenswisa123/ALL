CFLAGS = -ansi -pedantic -g 
proghash : HashT.o HashT_test.o
	gcc -o aprog HashT.o HashT_test.o 

HashT.o : HashT.c HashT.h
	gcc -c $(CFLAGS) HashT.c

HashT_test.o : HashT_test.c HashT.h
	gcc -c $(CFLAGS) HashT_test.c