CC = clang++

CFLAGS = -std=c++17 -pthread

TARGET1 = sequence_consistent

TARGET2 = relaxed

TARGET3 = release_acquire

TARGET4 = consume

all: $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)

$(TARGET1): $(TARGET1).cpp
			$(CC) $(CFLAGS) $(TARGET1).cpp
			./a.out

$(TARGET2): $(TARGET2).cpp
			$(CC) $(CFLAGS) $(TARGET2).cpp
			./a.out

$(TARGET3): $(TARGET3).cpp
			$(CC) $(CFLAGS) $(TARGET3).cpp
			./a.out

$(TARGET4): $(TARGET4).cpp
			$(CC) $(CFLAGS) $(TARGET4).cpp
			./a.out