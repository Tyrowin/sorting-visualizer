#include "utils.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <limits>

#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#undef max
#endif

// Clears the terminal screen
void clearScreen() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

// Waits for the user to press Enter
void waitForStep() {
    static bool first_call = true;
    if (first_call) {
        first_call = false;
        return;
    }
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Updated display function: draws each number as a bar, highlighting indices if provided, then waits for user
void displayArray(const std::vector<int>& arr, const std::vector<int>& highlighted) {
	clearScreen();
	for (size_t i = 0; i < arr.size(); i++) {
		// Check if current index should be highlighted
		if (std::find(highlighted.begin(), highlighted.end(), i) != highlighted.end())
			std::cout << "\033[31m" << std::string(arr[i], '#') << " (" << arr[i] << ")" << "\033[0m" << "\n";
		else
			std::cout << std::string(arr[i], '#') << " (" << arr[i] << ")" << "\n";
	}
	std::cout << std::endl;
	waitForStep();
}