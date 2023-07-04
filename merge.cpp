#include <iostream>
#include <vector>

// Merge two sorted subarrays into one sorted array
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int i = left;        // Index for the left subarray
    int j = mid + 1;     // Index for the right subarray
    int k = 0;           // Index for the merged subarray
    std::vector<int> temp(right - left + 1);  // Temporary array to store merged subarray

    // Merge elements from left and right subarray into temp
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy the remaining elements from the left subarray, if any
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements from the right subarray, if any
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the merged elements back to the original array
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

// Merge Sort function
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) {
        // Base case: The array has one or zero elements
        return;
    }

    int mid = left + (right - left) / 2;  // Calculate the middle index

    // Recursively sort the left and right subarrays
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted subarrays
    merge(arr, left, mid, right);
}

// Utility function to print an array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Test the mergeSort function
int main() {
    std::vector<int> arr = {9, 3, 17, 1, 25, 6, 11};
    int size = arr.size();

    std::cout << "Original array: ";
    printArray(arr);

    mergeSort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
