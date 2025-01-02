#include "../utils.h"
#include <vector>

// Function to merge two subarrays for Merge Sort
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        displayArray(arr); // Visualize the array after each merge
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        displayArray(arr); // Visualize the array after each merge
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        displayArray(arr); // Visualize the array after each merge
    }
}

// Function to perform Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid); // left subarray
        mergeSort(arr, mid + 1, right); // right subarray
        merge(arr, left, mid, right); // merge the two subarrays
    }
}