#include <iostream>
using namespace std;

// Function to implement Counting Sort algorithm
void CountingSort(int input_array[], int size, int range) {
  int output_array[size];
  int count_array[range];

  // Initialize all elements to 0 in the count array
  for (int i = 0; i < range; i++)
    count_array[i] = 0;

  // Count occurrences of each element in the input array
  for (int i = 0; i < size; i++)
    ++count_array[input_array[i]];

  // Calculate cumulative count in the count array
  for (int i = 1; i < range; i++)
    count_array[i] = count_array[i] + count_array[i - 1];

  // Place elements into the output array at proper positions
  // to get a sorted array in ascending order
  for (int i = 0; i < size; i++)
    output_array[--count_array[input_array[i]]] = input_array[i];

  // Copy output array elements to input array
  for (int i = 0; i < size; i++)
    input_array[i] = output_array[i];
}

int main() {
  int size = 0;
  int range = 10; // Assuming the range of input integers is 0-9

  // Input the size of the array
  cout << "Enter Size of array: " << endl;
  cin >> size;
  int myarray[size];

  // Input the elements of the array in the specified range
  cout << "Enter " << size << " integers in any order in the range of 0-9: " << endl;
  for (int i = 0; i < size; i++) {
    cin >> myarray[i];
  }

  // Display the array before sorting
  cout << "Before Sorting" << endl;
  for (int i = 0; i < size; i++) {
    cout << myarray[i] << " ";
  }
  cout << endl;

  // Call the CountingSort function to sort the array
  CountingSort(myarray, size, range);

  // Display the array after sorting
  cout << "After Sorting" << endl;
  for (int i = 0; i < size; i++) {
    cout << myarray[i] << " ";
  }

  return 0;
}
