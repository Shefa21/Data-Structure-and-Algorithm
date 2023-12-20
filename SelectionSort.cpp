#include <iostream>
using namespace std;

// Function to perform selection sort on an array
void selectionSort(int arr[]) {
  for (int i = 0; i < 4; i++) {
    int min = i;

    // Find the index of the minimum element in the unsorted part
    for (int j = i + 1; j < 5; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }

    // Swap the minimum element with the first element of the unsorted part
    if (min != i) {
      int temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
    }
  }
}

int main() {

  int myarr[5];

  // Input 5 integers in random order
  cout << "Enter 5 integers in random order: " << endl;
  for (int i = 0; i < 5; i++) {
    cin >> myarr[i];
  }

  // Display the unsorted array
  cout << "UNSORTED ARRAY: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarr[i] << "  ";
  }
  cout << endl;

  // Call the selectionSort function to sort the array
  selectionSort(myarr);

  // Display the sorted array
  cout << "SORTED ARRAY: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarr[i] << "  ";
  }
  return 0;
}
