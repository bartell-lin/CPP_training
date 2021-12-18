#include <string>
#include <vector>
#include "merge.h"
using namespace std;

bool Student::comparator(Student x, Student y) {
	return x.score < y.score;
};

void MergeSort::register_comparator(Student* s, memfn ptr) {
	lessfn = ptr;
	this->s = s;
};

void MergeSort::sort(vector<Student>& students) {
	merge_sort(students, 0, students.size() - 1);
}

void MergeSort::merge_sort(vector<Student>& students, int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		merge_sort(students, low, mid);
		merge_sort(students, mid + 1, high);
		merge(students, low, high, mid);
	}
}

void MergeSort::merge(vector<Student>& students, int low, int high, int mid) {
	int i = low;
	int k = low;
	int j = mid + 1;
	vector<Student> temp(high);

	while (i <= mid && j <= high) {
		if ((s->*lessfn)(students[i], students[j])) {
			temp[k] = students[i];
			k++;
			i++;
		} else {
			temp[k] = students[j];
			k++;
			j++;
		}
	}

	while (i <= mid) {
		temp[k] = students[i];
		k++;
		i++;
	}

	while (j <= high) {
		temp[k] = students[j];
		k++;
		j++;
	}

	for (i = low; i < k; i++) {
		students[i] = temp[i];
	}
}

