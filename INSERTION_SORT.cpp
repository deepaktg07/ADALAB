#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        int var = arr[i]; // Taken first element as sorted
        for (j = i - 1; j >= 0; j--) {
            if (arr[j] > var) {
                arr[j + 1] = arr[j]; // Shifting elements
            } else {
                break;
            }
        }
        arr[j + 1] = var;
    }

    cout << "Array after sorting:" << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Printing the array after being sorted
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int array[size];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    insertionSort(array, size);

    return 0;
}
