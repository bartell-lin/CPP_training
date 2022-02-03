CC = /opt/rh/gcc-toolset-10/root/usr/bin/g++
CFLAGS = -fcoroutines -std=c++2a -g -pthread -Wall

TARGET = main


all: $(TARGET) 

$(TARGET): $(TARGET).cpp
			$(CC) $(CFLAGS) $(TARGET).cpp
			./a.out