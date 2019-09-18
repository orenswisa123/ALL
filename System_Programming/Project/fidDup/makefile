CFLAGS = -ansi -pedantic -g
progrun: finDup.o HashT.o initialHash.o md5.o
		gcc -o progrun finDup.o HashT.o initialHash.o md5.o -lcrypto

md5.o : md5.c md5.h
		gcc -c $(CFLAGS) md5.c -lcrypto

initialHash.o : initialHash.c HashT.h
		gcc -c $(CFLAGS) initialHash.c

finDup.o : finDup.c md5.h HashT.h
		gcc -c $(CFLAGS) finDup.c
	
HashT.o : HashT.c HashT.h
		gcc -c $(CFLAGS) HashT.c