TARGET = simpleshell

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = simpleshell.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) output.txt

rebuild: clean all