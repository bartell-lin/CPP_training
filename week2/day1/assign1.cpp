#include <iostream>
#include <vector>

using namespace std;

void fib(long int* seq, int curr, int n);

int main() {
	int N = 50;
	long int seq[N];
	fib(seq, 0, N);

	for (int i = 0; i < N; i++) {
		cout << seq[i] << endl;
	}
	
}


void fib(long int* seq, int curr, int n) {
	if (curr == n) {
		return;
	}
	else if (curr == 0 || curr == 1) {
		seq[curr] = curr;
	} else {
		seq[curr] = seq[curr - 1] + seq[curr - 2];
	}
	curr++;
	fib(seq, curr, n);
}


/* 
One of the problems I encounted was that the numbers started getting too big to fit in the int type. Since int are only able to store numbers up to 2147483647, 
I needed to switch to a long int to properly store then. The 50th element of the Fibonacci sequence reaches 7 billion, which is too much. The program does 
not give an error, but I was able to detect the problem by printing out the elements of the array. 

*/