#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include "insertionSort.cpp"
#include "mergeSort.cpp"

template< class RandomIt >
void print(RandomIt start, RandomIt end) {
	while (start != end) {
		std::cout << *start << " ";
		++start;
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[]) {
	int a0[] = {56, 23, 11, 64, 43, 99, 72, 88, 3, 31};
	int t0[10];
	std::array<int, 10> a1 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	std::array<int, 10> t1;
	std::array<std::string, 10> a2 = {"ant", "bear", "cat", "dog", "elephant", "fox", "goat", "horse", "iguana", "jaguar"};
	std::array<std::string, 10> t2;
	std::vector<double> v = {4.2, 3.1, 5.6, 2.8, 1.9, 7.4, 6.3, 8.5, 9.8, 10.1};
	std::vector<double> tv(10);

	// Test Merge Sort
	std::cout << "Testing Merge Sort:" << std::endl;
	
	mergesort(&a0[0], &a0[10], &t0[0]);
	print(&a0[0], &a0[10]);

	mergesort(a1.begin(), a1.end(), t1.begin());
	print(a1.begin(), a1.end());

	mergesort(a2.begin(), a2.end(), t2.begin());
	print(a2.begin(), a2.end());

	std::reverse(a2.begin(), a2.end());
	print(a2.begin(), a2.end());

	mergesort(a2.begin(), a2.end(), t2.begin());
	print(a2.begin(), a2.end());

	mergesort(v.begin(), v.end(), tv.begin());
	print(v.begin(), v.end());

	// Reset data for Insertion Sort
	int a0_2[] = {56, 23, 11, 64, 43, 99, 72, 88, 3, 31};
	std::cout << "\nTesting Insertion Sort:" << std::endl;
	insertionsort(&a0_2[0], &a0_2[10]);
	print(&a0_2[0], &a0_2[10]);

	return 0;
}
