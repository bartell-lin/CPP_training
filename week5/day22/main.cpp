#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <thread>

using namespace std;
double calc(int num);

struct body {
	int ind;
	double mass;
	double position;
	double velocity;
	vector<double> forceVector;
	double totalForce;
	double acceleration;
};


int main() {
	int numBodies[] = {10, 20, 50, 100, 200, 500, 1000, 2000};
	[=]() {
		for (int i: numBodies) {
			double is = calc(i);
			cout << "Num Bodies: " << i << "  Num iteractions per sec: " << is << endl;
		}
	}();

}


double calc(int num) {
	int N = num;
	double G = 6.673e-11;
	double timestep = 0.05;
	double initial_mass = 1.0;
	double k = 300;
	double D = 0;
	vector<body> vbody;

	for (int i = 0; i < N; i++) {
		vector<double> temp (N, 0);
		double j = i;
		vbody.push_back({i, initial_mass, j, 0, temp, 0, 0});
	}

	auto func = [&](int i, double D, vector<vector<double>>& container) mutable {
		double tmp_force = 0;
		vector<double> tv(N, 0);

		for (int j = 0; j < i; j++) {
			if (i != j) {
				[&]() mutable {
					tv[j] = -vbody[j].forceVector[i];
					tmp_force += tv[j];
				}();
			}
		}

		for (int j = i; j < N; j++) {
			if (i != j) {
				[&]() mutable {
					tv[j] = (G * vbody[i].mass * vbody[j].mass * (vbody[i].position - vbody[j].position)) / (pow((vbody[i].position - vbody[j].position), 3));
					tmp_force += tv[j];
				}();
			}
		}

		container[i] = tv;
		[&]() mutable {vbody[i].totalForce = tmp_force;}();
		[&]() mutable {vbody[i].acceleration = vbody[i].totalForce/vbody[i].mass;}();
		[&]() mutable {vbody[i].velocity += D * vbody[i].acceleration;}();
	};

	for (int t = 0; t < k; t ++) {
		D += timestep;
		vector<thread> threads;
		vector<vector<double>> container(N);
		
		for (int i = 0; i < N; i++) {
			thread t(func, i, D, ref(container));
			threads.push_back(move(t));
		}
		for (int i = 0; i < N; i++) {
			threads[i].join();
		}
		for (int i = 0; i < N; i++) {
			vbody[i].forceVector = container[i];
			[&]() mutable {vbody[i].position += D * vbody[i].velocity;}();
		}
	}

	double is = 0;
	[&]() mutable {is = k * N * N / D;}();

	return is;
}