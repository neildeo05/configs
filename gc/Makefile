CFLAGS=-Wall -Wextra -pedantic


tests: gc.c tests.c
	$(CC) $(CFLAGS) -o tests gc.c tests.c
	
plain: tests.c
	$(CC) $(CFLAGS) -o tests tests.c

