#include "../utils.h"
#include <vector>

// Function to perform bubble sort on the array
void bubbleSort(std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]); // Swap if the element is greater than the next element
                displayArray(arr); // Visualize the array after each swap
            }
        }
    }
}