#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
#include <algorithm>
#include <thread>

using namespace std;
using namespace std::chrono;
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
	int numBodies[] = {10, 20, 50, 100, 200, 500};
	vector<thread> threads;

	int M[] = {1, 2, 3, 4, 5, 6, 7, 8};
	for (int i: M) {
		cout << "Using " << i << " threads" << endl;
		auto start = high_resolution_clock::now();
		for (int j = 0; j < i; j++) {
			thread t([=]{
				for (int k: numBodies) {
					double is = calc(k);
				}
			});
			threads.push_back(move(t)); 
		}

		for (auto& th: threads) {
			cout << "Thread " << th.get_id() << endl;
			th.join();
		}
		threads.clear();

		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		cout << duration.count() << " milliseconds" << endl;
		cout << endl;
	}
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

	for (int t = 0; t < k; t ++) {
		D += timestep;
		for (int i = 0; i < N; i++) {
			double tmp_force = 0;
			for (int j = 0; j < i; j++) {
				if (i != j) {
					[&]() mutable {
						vbody[i].forceVector[j] = -vbody[j].forceVector[i];
						tmp_force += vbody[i].forceVector[j];
					}();
				}
			}

			for (int j = i; j < N; j++) {
				if (i != j) {
					[&]() mutable {
						vbody[i].forceVector[j] = (G * vbody[i]. mass * vbody[j].mass * (vbody[i].position - vbody[j].position)) / (pow((vbody[i].position - vbody[j].position), 3));
						tmp_force += vbody[i].forceVector[j];
					}();
				}
			}
			[&]() mutable {vbody[i].totalForce = tmp_force;}();
			[&]() mutable {vbody[i].acceleration = vbody[i].totalForce/vbody[i].mass;}();
			[&]() mutable {vbody[i].velocity += D * vbody[i].acceleration;}();
			[&]() mutable {vbody[i].position += D * vbody[i].velocity;}();
		}
		this_thread::sleep_for(milliseconds(50));
	}

	double is = 0;
	[&]() mutable {is = k * N * N / D;}();

	return is;
}