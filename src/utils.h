#ifndef UTILS_H
#define UTILS_H

#include <vector>

// Updated declaration: now accepts optional highlighted indices.
void displayArray(const std::vector<int>& arr, const std::vector<int>& highlighted = {});
void waitForStep();

#endif // UTILS_H