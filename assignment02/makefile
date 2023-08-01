CC=gcc
CFLAGS_SANITIZE=-fsanitize=address
CFLAGS=-std=gnu99 -O1 


TARGETS = 
TARGETS += test_linked_list
# TARGETS += test

all: $(TARGETS)

%: %.c clean
	$(CC) $(CFLAGS) $(CFLAGS_SANITIZE) -o $@ $<
	./$@
	
clean: 
	rm -f $(TARGETS)