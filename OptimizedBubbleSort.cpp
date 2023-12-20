#include <iostream>
using namespace std;

// Function to perform optimized bubble sort on an array
void optimizedBubbleSort(int a[]) {
  int rounds = 0;

  // Iterate through the array
  for (int i = 0; i < 5; i++) {
    rounds++;
    int flag = false; // Flag to check if any swaps occurred in a round

    // Compare adjacent elements and swap if they are in the wrong order
    for (int j = 0; j < (5 - i - 1); j++) {
      if (a[j] > a[j + 1]) {
        flag = true;
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }

    // If no swaps occurred in a round, the array is already sorted
    if (flag == false) {
      break;
    }
  }

  // Display the number of rounds
  cout << "No of rounds : " << rounds << endl;
}

int main() {
  int myarray[5];

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

  // Call the optimizedBubbleSort function to sort the array
  optimizedBubbleSort(myarray);

  // Display the array after sorting
  cout << "After Sorting" << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarray[i] << " ";
  }

  return 0;
}
