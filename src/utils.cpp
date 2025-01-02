#include "utils.h"
#include <iostream>
#include <thread>
#include <chrono>

// Function to display the array as bars of '#' characters
void displayArray(const std::vector<int>& arr) {
    // ANSI escape codes to clear the screen and move the cursor to the top-left corner
    std::cout << "\033[2J\033[1;1H";

    for (int num : arr) {
        std::cout << std::string(num, '#') << "\n";
    }
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Pause for 500 milliseconds to visualize the sorting
}