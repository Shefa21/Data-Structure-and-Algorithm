#include<iostream> 
using namespace std; 

// A utility function to get the maximum value in arr[] 
int getMax(int arr[], int size) 
{ 
    int max = arr[0]; 
    for (int i = 1; i < size; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
    return max; 
} 

// Counting Sort for a particular digit (exp is the power of 10) 
void CountingSort(int arr[], int size, int exp) 
{ 
    int output[size]; // Output array 
    int count[10] = {0}; // Count array for digits 0-9 

    // Count the occurrences of each digit at the current place value
    for (int i = 0; i < size; i++) 
        count[(arr[i] / exp) % 10]++; 

    // Calculate the cumulative count 
    for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 

    // Place the elements in the output array based on their count and order
    for (int i = size - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    } 

    // Copy the sorted elements back to the original array 
    for (int i = 0; i < size; i++) 
        arr[i] = output[i]; 
} 

// Radix Sort implementation 
void RadixSort(int arr[], int size) 
{ 
    int max = getMax(arr, size); // Get the maximum value in the array 

    // Perform Counting Sort for every digit, starting from the least significant digit
    for (int exp = 1; max / exp > 0; exp *= 10) 
        CountingSort(arr, size, exp); 
} 

int main() 
{ 
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " integers in any order" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << endl << "Before Sorting: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    RadixSort(arr, size); // Call RadixSort to sort the array

    cout << endl << "After Sorting: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0; 
}
