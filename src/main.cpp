#include "utils.h"
#include "sorting/bubble_sort.h"
#include "sorting/quick_sort.h"
#include "sorting/merge_sort.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Function to generate random array of integers
void generateRandomArray(std::vector<int>& arr) {
	std::srand(static_cast<unsigned int>(std::time(0))); // Seed the random number generator
	for (int& num : arr) {
		num = std::rand() % 20 + 1;
	}
}

// Function to display the array
void showMenu() {
	std::cout << "1. Bubble Sort\n";
	std::cout << "2. Quick Sort\n";
	std::cout << "3. Merge Sort\n";
	std::cout << "4. Exit\n";
}

int main() {
	// Main function to test the sorting algorithms
	int choice;
	while (true) {
		std::vector<int> arr(10);
		generateRandomArray(arr);

		std::cout << "Original Array:\n";
		displayArray(arr);

		showMenu();
		std::cin >> choice;

		if (choice == 4) {
			break;
		}

		switch (choice) {
		case 1:
			std::cout << "Visualizing Bubble Sort...\n";
			bubbleSort(arr);
			break;
		case 2:
			std::cout << "Visualizing Quick Sort...\n";
			quickSort(arr, 0, static_cast<int>(arr.size()) - 1);
			break;
		case 3:
			std::cout << "Visualizing Merge Sort...\n";
			mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
			continue;
		}

		std::cout << "Sorted Array:\n";
		displayArray(arr);
	}

	return 0;
}