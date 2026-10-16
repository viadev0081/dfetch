# Binary file name
BINARY = ~/dfetch/bin/dfetch

CC = clang

# source code file
SRCS = $(wildcard src/*.c src/lib/distros/*.c)
CFLAGS = -Wall -Wextra -Isrc/lib

OBJS = $(SRCS:.c=.o)

$(BINARY): $(OBJS)
	$(CC) $(OBJS) -o $(BINARY)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Очистка бинарей... "
	@rm -f $(BINARY) 

run: build 
	@./$(BINARY)

