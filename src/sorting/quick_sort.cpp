#include "../utils.h"
#include <vector>

// Function to partition the array for Quick Sort
int partition(std::vector<int>& arr, int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			std::swap(arr[i], arr[j]); // Swap if the element is less than the pivot
			displayArray(arr);
		}
	}
	std::swap(arr[i + 1], arr[high]); // Swap the pivot element with the element at the correct position
	displayArray(arr);
	return (i + 1);
}

// Function to perform Quick Sort on the array
void quickSort(std::vector<int>& arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1); // left subarray
		quickSort(arr, pi + 1, high); // right subarray
	}
}