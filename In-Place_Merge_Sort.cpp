#include <iostream>
using namespace std;

void merge(int *arr, int l, int r){
    int mid = l + (r - l)/2;

    int index1 = l;
    int index2 = mid+1;
    if (arr[mid] <= arr[index2]) {
        return;
    }
 
    // Two pointers to maintain start
    // of both arrays to merge
    while (index1 <= mid && index2 <= r) {
 
        // If element 1 is in right place
        if (arr[index1] <= arr[index2]) {
            index1++;
        }
        else {
            int value = arr[index2];
            int mainIndex = index2;
 
            // Shift all the elements between element 1
            // element 2, right by 1.
            while (mainIndex != index1) {
                arr[mainIndex] = arr[mainIndex - 1];
                mainIndex--;
            }
            arr[index1] = value;
 
            // Update all the pointers
            index1++;
            mid++;
            index2++;
        }
    }
}

void mergeSort(int *arr, int l, int r){
    if(l >= r) return;
    int mid = l +(r - l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l , r); 
}

int main(){

    int n;
    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}