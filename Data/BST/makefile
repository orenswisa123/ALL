CFLAGS = -ansi -pedantic -g 

aprog : BST.o BST_test.o
	gcc -o aprog BST.o BST_test.o 

BST.o : BST.c BST.h
	gcc -c $(CFLAGS) BST.c

BST_test.o : BST_test.c BST.h
	gcc -c $(CFLAGS) BST_test.c