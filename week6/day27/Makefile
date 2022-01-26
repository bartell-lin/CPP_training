CC = clang++

CFLAGS = -std=c++17 -pthread -Wall

TARGET = parallel_accum

TARGET2 = async_accum

all: $(TARGET) $(TARGET2)

$(TARGET): $(TARGET).cpp
			$(CC) $(CFLAGS) $(TARGET).cpp
			./a.out

$(TARGET2): $(TARGET2).cpp
			$(CC) $(CFLAGS) $(TARGET2).cpp
			./a.out