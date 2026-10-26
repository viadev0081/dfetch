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

install:
	sudo cp $(BINARY) /usr/bin/

uninstall:
	sudo rm -f /usr/bin/dfetch

clean:
	@echo "Очистка бинарей... "
	@rm -f $(BINARY) 
	rm -f $(OBJS)

run: 
	$(BINARY)
