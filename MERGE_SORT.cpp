#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int high,int mid){
    int temp[high-low+1];
    int i=low;
    int k=0;
    int j=mid+1;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }
        else{
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
            k++;
            i++;
    }
    while(j<=high){
        temp[k]=arr[j];
            k++;
            j++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergesort(int arr[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}
int main() {
    int n, i;
    cout << "Enter the number of data elements to be sorted: ";
    cin >> n;
    int arr[n];
    cout<<"Enter the elements: "<<endl;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1);
    cout << "\nSorted Data: ";
    for (i = 0; i < n; i++) {
        cout << arr[i]<<"\t";
    }
    return 0;
}
