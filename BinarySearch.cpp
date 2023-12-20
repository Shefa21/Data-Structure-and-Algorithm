#include <iostream>
using namespace std;

// Function to perform binary search on an array
int binarySearch(int arr[], int left, int right, int x) {
  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == x) {
      return mid; // Element found, return its position
    } else if (arr[mid] < x) {
      left = mid + 1; // Adjust the search range to the right half
    } else {
      right = mid - 1; // Adjust the search range to the left half
    }
  }

  return -1; // Element not found
}

int main() {
  int myarr[10];
  int num;
  int output;

  // Input 10 elements in ascending order
  cout << "Please enter 10 elements in ASCENDING order" << endl;
  for (int i = 0; i < 10; i++) {
    cin >> myarr[i];
  }

  // Input an element to search
  cout << "Please enter an element to search" << endl;
  cin >> num;

  // Call the binarySearch function
  output = binarySearch(myarr, 0, 9, num);

  // Display the search result
  if (output == -1) {
    cout << "No Match Found" << endl;
  } else {
    cout << "Match found at position: " << output << endl;
  }

  return 0;
}
