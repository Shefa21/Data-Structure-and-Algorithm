#include <iostream>
using namespace std;

// Function to merge two halves of the array
void merge(int arr[], int l, int m, int r, int size) {
    int i = l;
    int j = m + 1;
    int k = l;

    // Create a temporary array to store merged elements
    int temp[size];

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        } else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    // Copy the remaining elements of the first half, if any
    while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of the second half, if any
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy the temp array to the original array
    for (int p = l; p <= r; p++) {
        arr[p] = temp[p];
    }
}

// Function to perform merge sort on the array
void mergeSort(int arr[], int l, int r, int size) {
    if (l < r) {
        // Find midpoint
        int m = (l + r) / 2;

        // Recursively perform merge sort on the first and second halves
        mergeSort(arr, l, m, size);
        mergeSort(arr, m + 1, r, size);

        // Merge the two halves
        merge(arr, l, m, r, size);
    }
}

int main() {
    cout << "Enter size of array: " << endl;
    int size;
    cin >> size;
    int myarray[size];

    cout << "Enter " << size << " integers in any order: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> myarray[i];
    }

    cout << "Before Sorting" << endl;
    for (int i = 0; i < size; i++) {
        cout << myarray[i] << " ";
    }
    cout << endl;

    mergeSort(myarray, 0, (size - 1), size); // Call mergeSort to sort the array

    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++) {
        cout << myarray[i] << " ";
    }

    return 0;
}
