#include <iostream>
#include <stdio.h>
#include "AVLTree.h"
#include "treap.h"
#include <chrono>
#include <random>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
start: //label
	cout << "What would you like to test?" << endl << "0 - AVL Tree" << endl << "1 - Treap" << endl << "2 - RB Tree" << endl << "3 - Sort Array" << endl;
	int input;
	cin >> input;
	switch (input) {
	case 0:
	{
		default_random_engine generator(time(0));
		uniform_int_distribution <int> distribution(0, 1000000);
		AVL AVLTr;
		int size;
		cout << "Enter size: ";
		cin >> size;

		int tmp;
		for (int i = 0; i < size; i++) {
			tmp = distribution(generator);
			AVLTr.Insert(AVLTr.GetRoot(), tmp);
		}
		if (size <= 100) {
			AVLTr.Show(AVLTr.GetRoot());
			cout << endl;
		}
		/*cout << endl << endl << "size of set: " << set.size() << endl;
		cout << endl;*/
		tmp = distribution(generator);

		cout << endl << "New generate element: " << tmp << endl;

		auto start_time = std::chrono::steady_clock::now();
		AVLTr.Insert(AVLTr.GetRoot(), tmp);
		auto finish_time = std::chrono::steady_clock::now();

		if (size <= 100) {
			cout << endl;
			AVLTr.Show(AVLTr.GetRoot());
		}
		cout << endl;
		auto result_time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish_time - start_time);
		cout << "Insert time: " << result_time.count() << endl;


		start_time = std::chrono::steady_clock::now();
		AVLTr.remove(AVLTr.GetRoot(), tmp);
		finish_time = std::chrono::steady_clock::now();
		if (size <= 100) {
			cout << endl;
			AVLTr.Show(AVLTr.GetRoot());
		}
		cout << endl;
		result_time = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
		cout << "Delete time: " << result_time.count() << endl;
		if (size <= 100) {
			cout << endl;
			AVLTr.Show(AVLTr.GetRoot());
		}
		cout << endl;
		start_time = std::chrono::steady_clock::now();
		AVLTr.Search(AVLTr.GetRoot(), tmp);
		finish_time = std::chrono::steady_clock::now();
		auto result = AVLTr.Search(AVLTr.GetRoot(), tmp);
		if (result != NULL) {
			cout << "Element " << tmp << " found." << endl;
		}
		else {
			cout << "Element " << tmp << " NOT found." << endl;
		}
		result_time = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
		cout << "Find time: " << result_time.count() << endl;

		AVLTr.Insert(AVLTr.GetRoot(), tmp);
		if (size <= 100) {
			cout << endl;
			AVLTr.Show(AVLTr.GetRoot());
		}
		start_time = std::chrono::steady_clock::now();
		AVLTr.Search(AVLTr.GetRoot(), tmp);
		finish_time = std::chrono::steady_clock::now();
		result = AVLTr.Search(AVLTr.GetRoot(), tmp);
		cout << endl;
		if (result != NULL) {
			cout << "Element " << tmp << " found." << endl;
		}
		else {
			cout << "Element " << tmp << " NOT found." << endl;
		}
		result_time = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
		cout << "Find time: " << result_time.count() << endl << endl;
		break;
	}
	case 1:
	{
		default_random_engine generator(time(0));
		uniform_int_distribution <int> distribution(0, 1000000);
		Treap TreapTr;
		int size;
		cout << "Size : ";
		cin >> size;
		int tmp;
		for (int i = 0; i < size; i++) {
			tmp = distribution(generator);
			TreapTr.insert(tmp);
		}
		if (size <= 100) {
			TreapTr.Show(TreapTr.GetRoot(), 0);
			cout << endl;
		}
		/*cout << endl << endl << "size of set: " << set.size() << endl;
		cout << endl;*/
		tmp = distribution(generator);
		cout << endl << "New generate element: " << tmp << endl;
		auto start_time = std::chrono::steady_clock::now();
		TreapTr.insert(tmp);
		auto finish_time = std::chrono::steady_clock::now();
		if (size <= 100) {
			cout << endl;
			TreapTr.Show(TreapTr.GetRoot(), 0);
		}
		cout << endl;
		auto result_time = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
		cout << "Insert time: " << result_time.count() << endl;
		start_time = std::chrono::steady_clock::now();
		TreapTr.remove(tmp);
		finish_time = std::chrono::steady_clock::now();
		if (size <= 100) {
			cout << endl;
			TreapTr.Show(TreapTr.GetRoot(), 0);
		}
		cout << endl;
		result_time = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
		cout << "Delete time: " << result_time.count() << endl;
		if (size <= 100) {
			cout << endl;
			TreapTr.Show(TreapTr.GetRoot(), 0);
		}
		cout << endl;
		start_time = std::chrono::steady_clock::now();
		TreapTr.Search(TreapTr.GetRoot(), tmp);
		finish_time = std::chrono::steady_clock::now();
		auto result = TreapTr.Search(TreapTr.GetRoot(), tmp);
		if (result != NULL) {
			cout << "Element " << tmp << " found." << endl;
		}
		else {
			cout << "Element " << tmp << " NOT found." << endl;
		}
		result_time = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
		cout << "Find time: " << result_time.count() << endl;
		TreapTr.insert(tmp);
		if (size <= 100) {
			cout << endl;
			TreapTr.Show(TreapTr.GetRoot(), 0);
		}
		cout << endl;
		start_time = std::chrono::steady_clock::now();
		TreapTr.Search(TreapTr.GetRoot(), tmp);
		finish_time = std::chrono::steady_clock::now();
		result = (TreapTr.Search(TreapTr.GetRoot(), tmp));
		if (result != NULL) {
			cout << "Element " << tmp << " found." << endl;
		}
		else {
			cout << "Element " << tmp << " NOT found." << endl;
		}
		result_time = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
		cout << "Find time: " << result_time.count() << endl << endl;
		break;
	}
	case 2:
	{
		default_random_engine generator(time(0));
		uniform_int_distribution <int> distribution(0, 1000000);
		set<int> set;
		std::set<int>::iterator it;
		int tmp;
		int n;
		cout << "Enter size: ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			tmp = distribution(generator);
			set.insert(tmp);
		}
		if (n <= 100) {
			for (it = set.begin(); it != set.end(); ++it) {
				cout << *it << ' ';
			}
			cout << endl;
		}
		//cout << endl << endl << "Size of set: " << set.size() << endl;
		cout << endl;
		tmp = distribution(generator);
		cout << "New generate element: " << tmp << endl;
		auto start_time = std::chrono::steady_clock::now();
		set.insert(tmp);
		auto finish_time = std::chrono::steady_clock::now();
		if (n <= 100) {
			cout << endl;
			for (it = set.begin(); it != set.end(); ++it) {
				cout << *it << ' ';
			}
		}
		cout << endl;
		auto result_time = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
		cout << "Insert time: " << result_time.count() << endl;
		start_time = std::chrono::steady_clock::now();
		set.erase(tmp);
		finish_time = std::chrono::steady_clock::now();
		if (n <= 100) {
			cout << endl;
			for (it = set.begin(); it != set.end(); ++it) {
				cout << *it << ' ';
			}
		}
		cout << endl;
		result_time = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
		cout << "Delete time: " << result_time.count() << endl;
		if (n <= 100) {
			cout << endl;
			for (it = set.begin(); it != set.end(); ++it) {
				cout << *it << ' ';
			}
		}
		cout << endl;
		start_time = std::chrono::steady_clock::now();
		set.find(tmp);
		finish_time = std::chrono::steady_clock::now();
		auto result = set.find(tmp);
		if (result != set.end()) {
			cout << "Element " << tmp << " found." << endl;
		}
		else {
			cout << "Element " << tmp << " NOT found." << endl;
		}
		result_time = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
		cout << "Find time: " << result_time.count() << endl;
		set.insert(tmp);
		if (n <= 100) {
			cout << endl;
			for (it = set.begin(); it != set.end(); ++it) {
				std::cout << *it << ' ';
			}
		}
		start_time = std::chrono::steady_clock::now();
		set.find(tmp);
		finish_time = std::chrono::steady_clock::now();
		result = set.find(tmp);
		cout << endl;
		if (result != set.end()) {
			cout << "Element " << tmp << " found." << endl;
		}
		else {
			cout << "Element " << tmp << " NOT found." << endl;
		}
		result_time = std::chrono::duration_cast<std::chrono::microseconds>(finish_time - start_time);
		cout << "Find time: " << result_time.count() << endl << endl;
		break;
	}
	case 3:
	{
		default_random_engine generator(time(0));
		uniform_int_distribution <int> distribution(0, 1000000);
		cout << "Enter size: ";
		int n;
		cin >> n;
		vector<int> vector;
		std::vector<int>::iterator it;
		for (int i = 0; i < n; i++) {
			vector.push_back(distribution(generator));
		}
		int tmp = vector.back();
		//cout << "Tmp: " << tmp << endl;

		if (n <= 100) {
			cout << "Array: " << endl;
			for (it = vector.begin(); it != vector.end(); ++it) {
				std::cout << *it << ' ';
			}cout << endl;
		}
		sort(vector.begin(), vector.end());
		if (n <= 100) {
			cout << endl << "Sort array:" << endl;
			for (it = vector.begin(); it != vector.end(); ++it) {
				std::cout << *it << ' ';
			}cout << endl;
		}
		cout << endl;
		tmp = distribution(generator);
		//tmp = 5000;
		cout << "New generate element: " << tmp << endl;
		auto start_time = std::chrono::steady_clock::now();
		vector.insert(find_if(vector.begin(), vector.end(), [&tmp](int i) {return i > tmp; }), tmp);
		auto finish_time = std::chrono::steady_clock::now();
		if (n <= 100) {
			cout << endl;
			for (it = vector.begin(); it != vector.end(); ++it) {
				std::cout << *it << ' ';
			}
		}
		auto result_time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish_time - start_time);
		cout << endl << "Insert time: " << result_time.count() << endl;


		start_time = std::chrono::steady_clock::now();
		vector.erase(find(vector.begin(), vector.end(), tmp));
		finish_time = std::chrono::steady_clock::now();
		//cout << "Array without tmp: " << endl;
		if (n <= 100) {
			cout << endl;
			for (it = vector.begin(); it != vector.end(); ++it) {
				std::cout << *it << ' ';
			}
		}
		result_time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish_time - start_time);
		cout << endl << "Delete time: " << result_time.count() << endl << endl;

		//cout << "Want to insert tmp: " << tmp << endl;
		start_time = std::chrono::steady_clock::now();
		it = find(vector.begin(), vector.end(), tmp);
		finish_time = std::chrono::steady_clock::now();
		if (it != vector.end()) {
			cout << "Element " << tmp << " found." << endl;
		}
		else {
			cout << "Element " << tmp << " NOT found." << endl;
		}
		result_time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish_time - start_time);
		cout << "Find time: " << result_time.count() << endl << endl;

		vector.insert(find_if(vector.begin(), vector.end(), [&tmp](int i) {return i > tmp; }), tmp);
		start_time = std::chrono::steady_clock::now();
		it = find(vector.begin(), vector.end(), tmp);
		finish_time = std::chrono::steady_clock::now();
		if (it != vector.end()) {
			cout << "Element " << tmp << " found." << endl;
		}
		else {
			cout << "Element " << tmp << " NOT found." << endl;
		}
		result_time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish_time - start_time);
		cout << "Find time: " << result_time.count() << endl << endl;



		break;
	}
	default:
	{
		cout << "Error input. Try again." << endl;
		goto start;
	}
	break;
	}
last_start:
	cout << endl << "Do you want to try again? (1 - yes || 0 - no)" << endl;
	cin >> input;
	switch (input)
	{
	case 0:
	{
		system("pause");
		return 0;
		break;
	}

	case 1:
	{
		goto start;
		break;
	}

	default:
	{
		cout << "Error input. Try again." << endl;
		goto last_start;
		break;
	}
	}
	system("pause");


}