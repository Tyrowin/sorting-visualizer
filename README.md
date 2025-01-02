# Visualizing Sorting Algorithms

This project implements various sorting algorithms in C++. The user can choose between different sorting methods through a menu interface. 

The following sorting algorithms are included:

- **Bubble Sort**: A simple comparison-based sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The process is repeated until the list is sorted.

- **Quick Sort**: An efficient sorting algorithm that uses a divide-and-conquer approach. It selects a 'pivot' element from the array and partitions the other elements into two sub-arrays according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.

- **Merge Sort**: Another divide-and-conquer algorithm that divides the array into halves, sorts each half, and then merges the sorted halves back together. This algorithm is known for its efficiency and stability.

## Building the Project

To build the project, you need to have CMake installed. Follow these steps:

1. Clone the repository or download the project files.
2. Open a terminal and navigate to the project directory.
3. Create a build directory:
   ```PowerShell
   mkdir build
   cd build
   ```
4. Run CMake to configure the project:
   ```PowerShell
   cmake ..
   ```
5. Build the project:
   ```PowerShell
   cmake --build .
   ```

## Running the Application
Run the application from the build directory using the following command in powershell:

```PowerShell
   .\Debug\SortingAlgorithms.exe
   ```

## Usage

Upon running the application, a menu will be displayed allowing you to select one of the sorting algorithms. After making a selection, the program will generate a random array, sort it using the chosen algorithm, and visualize the sorting process with ASCII art.

## Code Structure

- `main.cpp`: Contains the main function and menu logic
- `uitls.h` and `utils.cpp`: Utility functions for displaying the array.
- `bubble_sort.h` and `bubble_sort.cpp`: Implementation of the Bubble Sort algorithm.
- `quick_sort.h` and `quick_sort.cpp`: Implementation of the Quick Sort algorithm.
- `merge_sort.h` and `merge_sort.cpp`: Implementation of the Merge Sort algorithm.

## Contributing

Feel free to contribute to this project by adding more sorting algorithms or improving the existing implementations. Please submit a pull request for any changes you wish to propose.

## License
This project is licensed under the MIT License - see the LICENSE file for details.