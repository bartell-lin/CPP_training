CC = clang++

CFLAGS = -std=c++17 -pthread -fopenmp -Wall

TARGET = matrix_mult

TARGET2 = rect_mat

all: $(TARGET) $(TARGET2)

$(TARGET): $(TARGET).cpp
			$(CC) $(CFLAGS) $(TARGET).cpp
			./a.out

$(TARGET2): $(TARGET2).cpp
			$(CC) $(CFLAGS) $(TARGET2).cpp
			./a.out