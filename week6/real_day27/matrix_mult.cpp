#include <vector>
#include <iostream>
#include <stdlib.h> 
using namespace std;


template <typename T>
vector<vector<T>> mat_mult(const vector<vector<T>>& matrixA, const vector<vector<T>>& matrixB) {
	int dimension = matrixA.size();
	int maxdim = dimension * dimension;
	vector<T> flatA(maxdim);
	vector<T> flatB(maxdim);

	#pragma omp parallel for
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			flatA[i * dimension + j] = matrixA[i][j];
			flatB[j * dimension + i] = matrixB[i][j];
		}
	}


	int iOff, jOff;
	T tot;
	vector<vector<T>> matrixC(dimension, vector<T>(dimension, 0));
	#pragma omp parallel shared(matrixC) private(iOff, jOff, tot) num_threads(40) 
	{
	    #pragma omp for schedule(static) 
	    for (int i = 0;  i < dimension; i++) {
	        iOff = i * dimension;
	        for (int j = 0; j < dimension; j++) {
	            jOff = j * dimension;
	            tot = 0; 
	            for (int k = 0; k < dimension; k++) {
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
	vector<vector<int>> v = generate(3, 3);
	vector<vector<int>> out = mat_mult(v, v);

	for (auto i: out) {
		for (auto j: i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;


	vector<vector<float>> v2 = {{1.4, 2.2, 3.1}, {4.1, 5.9, 6.3}, {7.4, 8.4, 9.2}};
	vector<vector<float>> out2 = mat_mult(v2, v2);

	for (auto i: out2) {
		for (auto j: i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
}