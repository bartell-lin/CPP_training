#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;


template <typename T>
vector<vector<T>> mat_mult(const vector<vector<T>>& matrixA, const vector<vector<T>>& matrixB) {
	int x = matrixA.size();
	int y = matrixB.size();
	int z = matrixB[0].size();


	int maxdim1 = x * y;
	int maxdim2 = y * z;

	vector<T> flatA(maxdim1);
	vector<T> flatB(maxdim2);

	#pragma omp parallel for
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			flatA[i * y + j] = matrixA[i][j];
		}
	}

	#pragma omp parallel for
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < z; j++) {
			flatB[j * y + i] = matrixB[i][j];
		}
	}


	int iOff, jOff;
	T tot;
	vector<vector<T>> matrixC(x, vector<T>(z, 0));
	#pragma omp parallel shared(matrixC) private(iOff, jOff, tot) num_threads(40) 
	{
	    #pragma omp for schedule(static) 
	    for (int i = 0;  i < x; i++) {
	        iOff = i * y;
	        for (int j = 0; j < z; j++) {
	            jOff = j * y;
	            tot = 0; 
	            for (int k = 0; k < y; k++) {
	                tot += flatA[iOff + k] * flatB[jOff + k];
	            }
	            matrixC[i][j] = tot;
	        }
	    }
	}

	return matrixC;
}

vector<vector<int>> generate(int n, int m) {
	vector<vector<int>> mat(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat[i][j] = rand() % 10;
		}
	}
	return mat;
}


int main() {
	vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 2, 3}};
	vector<vector<int>> v2 = {{1, 2, 3, 3}, {4, 5, 6, 3}, {7, 8, 9, 3}};

	vector<vector<int>> out = mat_mult(v, v2);

	for (auto i: out) {
		for (auto j: i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;


	vector<vector<int>> v3 = generate(4, 3);
	vector<vector<int>> v4 = generate(3, 5);

	vector<vector<int>> out2 = mat_mult(v3, v4);

	for (auto i: out2) {
		for (auto j: i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;

}