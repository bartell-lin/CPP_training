class Calandar {
public:
	int month;
	int year;
	int** cal;
	int** get();
	void print();
	void set(int month, int year);
	Calandar(int m, int y);
	~Calandar();
};