#include <iostream>
#include <vector>
#include <cstdlib>
#include <thread>
#include <chrono>

void displayArray(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << i + 1 << ": " << std::string(arr[i], '#') << "\n";
    }
    std::cout << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                // Visualize after each swap
                system("CLS"); // Clear the console (use "clear" on Linux/Mac)
                displayArray(arr);
            }
        }
    }
}

int main() {
    // Generate random data
    std::vector<int> arr(10);
    for (int& x : arr) {
        x = rand() % 20 + 1; // Random numbers between 1 and 20
    }

    std::cout << "Original Array:\n";
    displayArray(arr);

    std::cout << "Visualizing Bubble Sort...\n";
    bubbleSort(arr);

    std::cout << "Sorted Array:\n";
    displayArray(arr);

    return 0;
}
