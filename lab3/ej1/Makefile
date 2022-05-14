CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99
CC = gcc
SRC = array_helpers.c weather.c weather_utils.c main.c 
OBJS = $(SRC:.c=.o)

all: weather

objetos:
	$(CC) $(CFLAGS) -c $(SRC)

weather: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f weather $(OBJS)

.PHONY: clean
