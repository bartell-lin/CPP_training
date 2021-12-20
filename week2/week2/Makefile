OBJS	= assign1.o bank_account.pb.o
OBJS2    = test.o bank_account.pb.o
SOURCE	= assign1.cpp bank_account.pb.cc 
SOURCE2  = test.cpp bank_account.pb.cc 
HEADER	= 
OUT	= binaryfilename
OUT2	= testfile
CC	 = clang++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS) `pkg-config --cflags --libs protobuf`
	./$(OUT)

assign1.o: assign1.cpp
	$(CC) $(FLAGS) assign1.cpp -std=c++17

bank_account.pb.o: bank_account.pb.cc
	$(CC) $(FLAGS) bank_account.pb.cc -std=c++17

test.o: test.cpp
	$(CC) $(FLAGS) test.cpp -std=c++17


test: $(OBJS2)
	$(CC) -g $(OBJS2) -o $(OUT2) $(LFLAGS) `pkg-config --cflags --libs protobuf`
	./$(OUT2)

clean:
	rm -f $(OBJS) $(OUT)
	rm -f $(OBJS2) $(OUT2)