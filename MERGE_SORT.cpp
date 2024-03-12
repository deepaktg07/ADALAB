#include <iostream>
using namespace std;

void Merge(int arr[], int low, int high, int mid) {
    int i, j, k;
    int temp[high - low + 1];
    i = low;
    k = 0;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            k++;
            i++;
        } else {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void MergeSort(int arr[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, high, mid);
    }
}

int main() {
    int n, i;
    cout << "Enter the number of data elements to be sorted: ";
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    MergeSort(arr, 0, n - 1);
    cout << "\nSorted Data: ";
    for (i = 0; i < n; i++) {
        cout << "->" << arr[i];
    }
    return 0;
}
