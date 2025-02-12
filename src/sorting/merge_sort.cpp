#include "../utils.h"
#include <vector>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <algorithm>

// Anonymous namespace to limit helper visibility
namespace {
    // Updated helper: displays subarray elements as horizontal bars,
    // highlighting indices in 'highlighted' (in red), then waits for user input
    void displaySubarray(const std::vector<int>& arr, int start, int end, const std::string& label, const std::vector<int>& highlighted = {}) {
        if(start > end) return;
        std::cout << label << ":\n";
        for (int i = start; i <= end; ++i) {
            if (std::find(highlighted.begin(), highlighted.end(), i) != highlighted.end())
                std::cout << "\033[31m" << std::string(arr[i], '#') << " (" << arr[i] << ")   " << "\033[0m";
            else
                std::cout << std::string(arr[i], '#') << " (" << arr[i] << ")   ";
        }
        std::cout << "\n";
        waitForStep();
    }
}

// Function to merge two subarrays with descriptive messaging
void merge(std::vector<int>& arr, int left, int mid, int right) {
    displaySubarray(arr, left, mid, "Left part");
    displaySubarray(arr, mid + 1, right, "Right part");

    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);
    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        displaySubarray(arr, left, right, "Merging", {k});
        std::cout << "Comparing left element " << L[i] << " and right element " << R[j] << ". ";
        if (L[i] <= R[j]) {
            std::cout << "Left element is smaller or equal; placing it at index " << k << ".\n";
            waitForStep();
            arr[k] = L[i];
            i++;
        } else {
            std::cout << "Right element is smaller; placing it at index " << k << ".\n";
            waitForStep();
            arr[k] = R[j];
            j++;
        }
        k++;
        displayArray(arr);
    }
    while (i < n1) {
        std::cout << "Copying remaining left element " << L[i] << " into main array at index " << k << ".\n";
        waitForStep();
        arr[k] = L[i];
        i++; k++;
        displaySubarray(arr, left, right, "Merging", {k - 1});
        displayArray(arr);
    }
    while (j < n2) {
        std::cout << "Copying remaining right element " << R[j] << " into main array at index " << k << ".\n";
        waitForStep();
        arr[k] = R[j];
        j++; k++;
        displaySubarray(arr, left, right, "Merging", {k - 1});
        displayArray(arr);
    }
}

// Function to perform Merge Sort with added visualization clarity
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}