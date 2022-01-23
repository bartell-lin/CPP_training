CC = clang++

CFLAGS = -std=c++17 -pthread

TARGET1 = hailstone_race_condition

TARGET2 = hailstone_fixed

TARGET3 = trading_deadlock

TARGET4 = trading_fixed

all: $(TARGET2) $(TARGET4)

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