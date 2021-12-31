OBJS	= assign1.o BigNumber.o
OBJS2    = assign2.o Calandar.o
SOURCE	= assign1.cpp BigNumber.cpp 
SOURCE2  = assign2.cpp Calandar.cpp
HEADER	= 
OUT	= a_one_file
OUT2	= a_two_file
CC	 = clang++
FLAGS	 = -g -c -Wall -std=c++17
LFLAGS	 = 

assign1.o: assign1.cpp
	$(CC) $(FLAGS) assign1.cpp

assign2.o: assign2.cpp
	$(CC) $(FLAGS) assign2.cpp

BigNumber.o: BigNumber.cpp
	$(CC) $(FLAGS) BigNumber.cpp

Calandar.o: Calandar.cpp
	$(CC) $(FLAGS) Calandar.cpp

a1: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
	./$(OUT)


a2: $(OBJS2)
	$(CC) -g $(OBJS2) -o $(OUT2) $(LFLAGS)
	./$(OUT2)

clean:
	rm -f $(OBJS) $(OUT)
	rm -f $(OBJS2) $(OUT2)