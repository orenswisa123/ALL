CFLAGS = -ansi -pedantic -g 

aprog : darray_void.o darray_test.o
	gcc -o aprog darray_void.o darray_test.o 

darray_void.o : darray_void.c darray_void.h
	gcc -c $(CFLAGS) darray_void.c

darray_test.o : darray_test.c darray_void.h
	gcc -c $(CFLAGS) darray_test.c