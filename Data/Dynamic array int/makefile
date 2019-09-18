CFLAGS = -pedantic -g -wall

aprog : darray_int.o darray_test.o
	gcc -o aprog darray_int.o darray_test.o 

darray_int.o : darray_int.c darray_int.h
	gcc -c $(CFLAGS) darray_int.c

darray_test.o : darray_test.c darray_int.h
	gcc -c $(CFLAGS) darray_test.c