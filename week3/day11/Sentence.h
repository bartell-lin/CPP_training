#include <vector>
#include <string>

class Sentence {
private:
	char* sentence;
	std::vector<int> vsentence;
public:
	Sentence(char* sent);
	Sentence(const Sentence& other);
	Sentence& operator=(const Sentence& other);
	Sentence(Sentence&& other);
	Sentence& operator==(Sentence&& other);
	char* data();
	int num_words() const;
	std::string get_word(int n);
	void replace(char* sent);
	~Sentence();
};