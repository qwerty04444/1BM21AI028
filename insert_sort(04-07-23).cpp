#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int size = arr.size();

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<int> arr = {9, 3, 17, 1, 25, 6, 11};

    std::cout << "Original array: ";
    printArray(arr);

    insertionSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
