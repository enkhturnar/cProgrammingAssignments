CC=gcc
CFLAGS=-std=gnu99 -O1

TARGETS = 
TARGETS += test

all: $(TARGETS)

%: %.c clean
	$(CC) $(CFLAGS) -o $@ $<
	valgrind -q --leak-check=full ./$@

clean: 
	rm -f $(TARGETS)