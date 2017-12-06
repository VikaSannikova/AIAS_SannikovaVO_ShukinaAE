#include <vector>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>

using namespace std;

std::vector<int> vec = {1,2,3,4,5,7,8,9}; //втф
int val = 1;
int predicat(int i) {
	if (val <= vec.front())
		return vec.size();
	if (val >= vec.back())
		return 0;
	return vec[i-1] > val;
}

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
	if (it != vector.end()) {
		cout << "element " << tmp << " found" << endl;
	}
	else {
		cout << "element " << tmp << " NOT found" << endl;
	}
	auto result_time = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
	cout << "find time: " << result_time.count() << endl;


	start_time = std::chrono::steady_clock::now();
	vector.erase(find(vector.begin(), vector.end(), tmp)); //удаляет первый элемент
	finish_time = std::chrono::steady_clock::now();
	cout << "Array without tmp: " << endl;
	for (it = vector.begin(); it != vector.end(); ++it) {
		std::cout << *it << ' ';
	}
	result_time = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
	cout << endl << "Erase time: " << result_time.count() << endl;




	//start_time = std::chrono::steady_clock::now();
	cout << "********************************" << endl << endl;
	//cout<<vector.at( find            );





	for (it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << ' ';
	}
	cout << endl;
	vec.insert(find_if(vec.begin(), vec.end(), &predicat), val);
	for (it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << ' ';
	}


	//for (it = vector.begin(); it != vector.end(); ++it) {
	//	std::cout << *it << ' ';
	//}
	//cout << endl;
	//int i = 0;
	//vector.insert(find_if(vector.begin(), vector.end(), predicat(i,vector,tmp)) + 1, tmp);
	//for (it = vector.begin(); it != vector.end(); ++it) {
	//	std::cout << *it << ' ';
	//}



	system("pause");
	return 0;
}