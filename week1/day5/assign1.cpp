#include <iostream>
#include <vector>
#include "assert.h"

using namespace std;

vector< vector<int> > matrix_mult(vector< vector<int> > a, vector< vector<int> > b);

int main() {
	vector< vector<int> > a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 2, 3}};
	vector< vector<int> > b = {{2, 4}, {5, 3}, {4, 7}, {4, 4}};
	vector< vector<int> > out = {{40, 47}, {100, 119}, {43, 65}};

	vector< vector<int> > c = matrix_mult(a, b);

	assert(c == out); // Checks if output is correct

	cout << "Matrix A" << endl;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Matrix B" << endl;

	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Matrix C" << endl;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
}


vector< vector<int> > matrix_mult(vector< vector<int> > a, vector< vector<int> > b) {
	assert(a[0].size() == b.size());  // Checks if dimensions are valide for multiplication

	int m = a.size();
	int n = b.size();
	int p = b[0].size();
	vector< vector<int> > prod;

	for (int i = 0; i < m; i++) {
		vector<int> rows;
		for (int j = 0; j < p; j++) {
			int x = 0;
			for (int k = 0; k < n; k++) {
				x += a[i][k] * b[k][j];
			}
			rows.push_back(x);
		}
		prod.push_back(rows);
	}

	return prod;
}

