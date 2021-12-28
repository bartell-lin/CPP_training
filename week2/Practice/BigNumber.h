#include <vector>
using namespace std;

typedef vector<vector<>unsigned char> numvec;

class BigNumber {
private:
	bool overflow;
	union {
		long lnum;
		unsigned char cnum[64];
	} actualUnion;

public:
	long bnumber;
	void multiply(const BigNumber& input, BigNumber& output);
	std::string number() const;
	void set(long num);
	void set(std::string);
	BigNumber(long num);
	BigNumber(std::string num);
	numvec simulate_multiply(BigNumber& input);
	void print(numvec v);
};
