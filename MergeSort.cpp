#include <iostream>
using namespace std;

// Function to merge two sorted subarrays into a single sorted subarray
void merge(int arr[], int l, int m, int r) {
  int i = l;
  int j = m + 1;
  int k = l;

  // Create a temporary array to store merged elements
  int temp[5];

  // Merge the two subarrays
  while (i <= m && j <= r) {
    if (arr[i] <= arr[j]) {
      temp[k] = arr[i];
      i++;
    } else {
      temp[k] = arr[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of the first subarray
  while (i <= m) {
    temp[k] = arr[i];
    i++;
    k++;
  }

  // Copy the remaining elements of the second subarray
  while (j <= r) {
    temp[k] = arr[j];
    j++;
    k++;
  }

  // Copy the merged elements back to the original array
  for (int p = l; p <= r; p++) {
    arr[p] = temp[p];
  }
}

// Function to implement merge sort
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // Find the midpoint
    int m = (l + r) / 2;

    // Recursively sort the first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted halves
    merge(arr, l, m, r);
  }
}

int main() {
  int myarray[5];
  int arr_size = 5;

  // Input 5 integers in any order
  cout << "Enter 5 integers in any order: " << endl;
  for (int i = 0; i < 5; i++) {
    cin >> myarray[i];
  }

  // Display the array before sorting
  cout << "Before Sorting" << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarray[i] << " ";
  }
  cout << endl;

  // Call the mergeSort function to sort the array
  mergeSort(myarray, 0, (arr_size - 1));

  // Display the array after sorting
  cout << "After Sorting" << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarray[i] << " ";
  }

  return 0;
}
