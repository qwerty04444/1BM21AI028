#include <iostream>
#include <vector>


int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;       

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);  
        }
    }

    std::swap(arr[i + 1], arr[high]); 
    return i + 1;
}

// Quick Sort function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);  

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Utility function to print an array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {9, 3, 17, 1, 25, 6, 11};
    int size = arr.size();

    std::cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
