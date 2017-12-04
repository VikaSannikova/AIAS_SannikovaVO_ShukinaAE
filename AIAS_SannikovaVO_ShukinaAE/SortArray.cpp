#include <vector>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	default_random_engine generator(time(0));
	uniform_int_distribution <int> distribution(0, 1000);
	cout << "Enter size: ";
	int n;
	cin >> n;
	vector<int> vector;
	std::vector<int>::iterator it;

	for (int i = 0; i < n; i++) {
		vector.push_back(distribution(generator));
	}
	int tmp = vector.back();
	cout << "tmp: " << tmp << endl;
	for (it = vector.begin(); it != vector.end(); ++it) {
		std::cout << *it << ' ';
	}
	cout << endl << "Sort array:" << endl;
	sort(vector.begin(), vector.end());
	for (it = vector.begin(); it != vector.end(); ++it) {
		std::cout << *it << ' ';
	}
	cout << endl << endl;

	auto start_time = std::chrono::steady_clock::now();
	it = find(vector.begin(), vector.end(), tmp);
	auto finish_time = std::chrono::steady_clock::now();
		if (it!=vector.end()) {
			cout << "element " << tmp << " found" << endl;
		}
		else {
			cout << "element " << tmp << " NOT found" << endl;
		}
	auto result_time = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
	cout << "find time: " << result_time.count() << endl;
	

	start_time = std::chrono::steady_clock::now();
	vector.erase(find(vector.begin(), vector.end(), tmp));
	finish_time = std::chrono::steady_clock::now();
	cout << "Array without tmp: " << endl;
	for (it = vector.begin(); it != vector.end(); ++it) {
		std::cout << *it << ' ';
	}
	result_time = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
	cout << endl <<"Erase time: " << result_time.count() << endl;


	system("pause");
	return 0;
}