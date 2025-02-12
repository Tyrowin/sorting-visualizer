#include "../utils.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

// Anonymous namespace to limit helper visibility
namespace {
    // Updated helper: displays subarray elements as horizontal bars,
    // highlighting indices in 'highlighted' (in red), then waits for user input
    void displaySubarray(const std::vector<int>& arr, int low, int high, const std::string& label, const std::vector<int>& highlighted = {}) {
        if(low > high) return;
        std::cout << label << ":\n";
        for (int i = low; i <= high; ++i) {
            if (std::find(highlighted.begin(), highlighted.end(), i) != highlighted.end())
                std::cout << "\033[31m" << std::string(arr[i], '#') << " (" << arr[i] << ")   " << "\033[0m";
            else
                std::cout << std::string(arr[i], '#') << " (" << arr[i] << ")   ";
        }
        std::cout << "\n";
        waitForStep();
    }
}

// Modified partition: now prints descriptive messages for each comparison and swap
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    std::cout << "Pivot selected: " << pivot << std::endl;
    waitForStep();
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        displaySubarray(arr, low, high, "Comparing", {j, high});
        std::cout << "Comparing element " << arr[j] << " with pivot " << pivot << ". ";
        if (arr[j] < pivot) {
            std::cout << "It is smaller; swap it with element at index " << (i + 1) << ".\n";
            waitForStep();
            i++;
            std::swap(arr[i], arr[j]);
            displayArray(arr);
        } else {
            std::cout << "It is not smaller; no swap performed.\n";
            waitForStep();
        }
    }
    std::cout << "Swapping pivot " << pivot << " into position " << (i + 1) << ".\n";
    waitForStep();
    std::swap(arr[i + 1], arr[high]);
    displayArray(arr);
    return (i + 1);
}

// Function to perform Quick Sort on the array
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        displaySubarray(arr, low, pi - 1, "Left subarray");
        quickSort(arr, low, pi - 1); // left subarray
        displaySubarray(arr, pi + 1, high, "Right subarray");
        quickSort(arr, pi + 1, high); // right subarray
    }
}