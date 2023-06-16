CC = gcc
DIR = chapter2
CFLAGS = -Wall -I./common
COMMON_SRCS = $(wildcard common/*.c)
COMMON_OBJS = $(COMMON_SRCS:.c=.o)

.PHONY: clean

$(COMMON_OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%: $(DIR)/%.c $(COMMON_OBJS)
	$(CC) $(CFLAGS) $< $(COMMON_OBJS) -o $@

clean:
	rm -f $(COMMON_OBJS) $(shell find $(DIR) -type f -executable)
