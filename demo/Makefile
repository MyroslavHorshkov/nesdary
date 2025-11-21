CC = gcc
CFLAGS = -Wall -Wextra -O2 -g
TARGET = calc
SRC = proto.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
