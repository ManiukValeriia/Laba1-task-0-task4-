TARGET = task4_result

CC = gcc

CFLAGS = -Wall -g

SRCS = main.c ArrayList.c

OBJS = $(SRCS:.c=.o)

HEADERS = ArrayList.h

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
