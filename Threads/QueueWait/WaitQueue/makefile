CFLAGS = -ansi -pedantic -g

aprog : wQueue.o wQueueTest.o
	gcc -o aprog wQueue.o wQueueTest.o -lpthread

wQueueTest.o : wQueueTest.c
	gcc -c $(CFLAGS) wQueueTest.c -lpthread

wQueue.o : wQueue.c
	gcc -c $(CFLAGS) wQueue.c -lpthread