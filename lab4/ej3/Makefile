CFLAGS = -g -Wall -Werror -Wextra -pedantic -std=c99
CC = gcc
SRC = array_helpers.c list.c main.c 
OBJS = $(SRC:.c=.o)

all: average

objetos:
	$(CC) $(CFLAGS) -c $(SRC)

average: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f average $(OBJS)

.PHONY: clean
