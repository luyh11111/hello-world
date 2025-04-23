CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = program
SRC_DIR = src
INCLUDE_DIR = include
SRCS = main.c $(SRC_DIR)/utils.c $(SRC_DIR)/math_ops.c $(SRC_DIR)/string_ops.c $(SRC_DIR)/file_ops.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
	rm -f test_file.txt test_file_copy.txt test_report.txt 