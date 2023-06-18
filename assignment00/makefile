CC=gcc
CFLAGS_SANITIZE=-std=gnu99 -O1 -fsanitize=address

TARGETS = 
TARGETS += test

all: $(TARGETS)

%: %.c clean
	$(CC) $(CFLAGS_SANITIZE) -o $@ $<
	./$@

clean: 
	rm -f $(TARGETS)