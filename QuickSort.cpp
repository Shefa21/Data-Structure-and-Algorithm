#include <iostream>
using namespace std;

// Function to partition the array into two halves and return the index of the pivot element
int Partition(int arr[], int s, int e) {
  int pivot = arr[e];
  int pIndex = s;

  // Iterate through the array and rearrange elements based on the pivot
  for (int i = s; i < e; i++) {
    if (arr[i] < pivot) {
      // Swap arr[i] and arr[pIndex]
      int temp = arr[i];
      arr[i] = arr[pIndex];
      arr[pIndex] = temp;
      pIndex++;
    }
  }

  // Swap pivot element with the element at pIndex
  int temp = arr[e];
  arr[e] = arr[pIndex];
  arr[pIndex] = temp;

  return pIndex;
}

// Function to implement the QuickSort algorithm
void QuickSort(int arr[], int s, int e) {
  if (s < e) {
    int p = Partition(arr, s, e);

    // Recursive QuickSort calls for the left and right partitions
    QuickSort(arr, s, (p - 1));
    QuickSort(arr, (p + 1), e);
  }
}

int main() {
  int size = 0;

  // Input the size of the array
  cout << "Enter Size of array: " << endl;
  cin >> size;
  int myarray[size];

  // Input the elements of the array
  cout << "Enter " << size << " integers in any order: " << endl;
  for (int i = 0; i < size; i++) {
    cin >> myarray[i];
  }

  // Display the array before sorting
  cout << "Before Sorting" << endl;
  for (int i = 0; i < size; i++) {
    cout << myarray[i] << " ";
  }
  cout << endl;

  // Call the QuickSort function to sort the array
  QuickSort(myarray, 0, (size - 1));

  // Display the array after sorting
  cout << "After Sorting" << endl;
  for (int i = 0; i < size; i++) {
    cout << myarray[i] << " ";
  }

  return 0;
}
