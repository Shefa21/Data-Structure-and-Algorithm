#include<iostream> 
using namespace std;

// Function to perform Shell Sort on an array
void ShellSort(int arr[], int n) {
    // Start with a large gap and reduce it in each iteration
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform insertion sort for the elements at a given gap
        for (int j = gap; j < n; j += 1) {
            int temp = arr[j];
            int i = 0;

            // Compare and shift elements within the current gap
            for (i = j; (i >= gap) && (arr[i - gap] > temp); i -= gap) {
                arr[i] = arr[i - gap];
            }

            // Place the current element at its correct position
            arr[i] = temp;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;

    int arr1[n], arr2[n];

    cout << "Enter " << n << " integers in any order" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    cout << endl << "Before Sorting: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }

    cout << endl << endl << "SHELL SORT " << endl;

    ShellSort(arr1, n); // Call ShellSort to sort the array

    cout << endl << "After Sorting: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }

    return 0;
}
