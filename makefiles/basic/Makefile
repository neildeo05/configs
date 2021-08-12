INCLUDEDIRS=-I../gc
CFLAGS= -Wall -Wextra -pedantic
FILE= main 
OBJ=main.o
$(FILE): $(OBJ)
	$(CC) -o $@ $<
%.o: %.c
	$(CC) $(INCLUDEDIRS) $(CFLAGS) -o $@ -c $<
clean:
	rm -r $(FILE) $(OBJ)
