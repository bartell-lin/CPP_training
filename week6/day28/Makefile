CC = /opt/rh/gcc-toolset-11/root/usr/bin/g++

CFLAGS = -std=c++2a -fcoroutines -g -gdwarf-2 -pthread -Wall

TARGET = main


all: $(TARGET) 

$(TARGET): $(TARGET).cpp
			$(CC) $(CFLAGS) $(TARGET).cpp
			./a.out