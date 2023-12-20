#include <iostream>
using namespace std;

// Function to perform linear search on an array
void linearSearch(int a[], int n) {
  int temp = -1;

  // Iterate through the array to find the element
  for (int i = 0; i < 5; i++) {
    if (a[i] == n) {
      cout << "Element found at position: " << i + 1 << endl;
      temp = 0;
      break; // Break the loop if the element is found
    }
  }

  // If the element is not found, display a message
  if (temp == -1) {
    cout << "No Element Found" << endl;
  }
}

int main() {
  int arr[5];

  // Input 5 elements for the array
  cout << "Please enter 5 elements of the Array" << endl;
  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
  }

  // Input an element to search
  cout << "Please enter an element to search" << endl;
  int num;
  cin >> num;

  // Call the linearSearch function
  linearSearch(arr, num);

  return 0;
}
