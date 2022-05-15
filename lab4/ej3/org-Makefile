CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99
CC = gcc
SRC = helpers.c sort.c main.c 
OBJS = $(SRC:.c=.o)

all: mysort

objetos:
	$(CC) $(CFLAGS) -c $(SRC)

mysort: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f mysort $(OBJS)

.PHONY: clean
