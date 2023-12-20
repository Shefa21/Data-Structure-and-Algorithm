#include <iostream>
using namespace std;

// Function to perform insertion sort on an array
void insertionSort(int arr[]) {
  int key;
  int j = 0;
  for (int i = 1; i < 5; i++) {
    key = arr[i];
    j = i - 1;

    // Shift elements greater than the key to the right
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }

    // Place the key in its correct position
    arr[j + 1] = key;
  }
}

int main() {
  int myarray[5];

  // Input 5 integers in any order
  cout << "Enter 5 integers in any order" << endl;
  for (int i = 0; i < 5; i++) {
    cin >> myarray[i];
  }

  // Display the array before sorting
  cout << "Before Sorting: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarray[i] << " ";
  }

  // Call the insertionSort function to sort the array
  insertionSort(myarray);

  // Display the array after sorting
  cout << endl << "After Sorting: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarray[i] << " ";
  }

  return 0;
}
