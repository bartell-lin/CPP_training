#include <string>
#include <vector>
#include <iostream>
#include "assert.h"
#include "merge.h"

using namespace std;

int main() {
	MergeSort ms;
	Student s1 = {"1", 70};
	Student s2 = {"2", 20};
	Student s3 = {"3", 93};
	Student s4 = {"4", 82};
	Student s5 = {"5", 21};
	Student s6 = {"6", 68};
	Student s;
	ms.register_comparator(&s, &Student::comparator);
	vector<Student> student_list = {s1, s2, s3, s4, s5, s6};
	ms.sort(student_list);

	int correct[6] = {20, 21, 68, 70, 82, 93}; 

	for (int i = 0; i < student_list.size(); i++) {
		cout << student_list[i].score << endl;

		assert(student_list[i].score == correct[i]);
	}

}