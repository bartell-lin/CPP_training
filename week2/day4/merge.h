#include <string>
#include <vector>
using namespace std;

struct Student {
	string studentId;
	int score;
	bool comparator(Student x, Student y);
};

class MergeSort {
public:
	typedef bool (Student::*memfn)(Student x, Student y);
	memfn lessfn;
	Student* s;
	void register_comparator(Student* s, memfn ptr);
	void sort(vector<Student>& students);
private:
	void merge_sort(vector<Student>& students, int low, int high);
	void merge(vector<Student>& students, int low, int high, int mid);
};