#include <iostream>
using namespace std;

void merge(int *arr, int l, int r){
    int mid = l + (r - l)/2;

    int l1 = mid - l + 1;
    int l2 = r - mid;

    int *first = new int[ l1];
    int *second = new int [l2];

    int mainIndex = l;

    for(int i=0; i < l1; i++){
        first[i]=arr[mainIndex++];
    }

    mainIndex = mid + 1;
    for(int i=0; i < l2; i++){
        second[i]=arr[mainIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainIndex = l;

    while(index1 < l1 && index2 < l2) {
        if(first[index1] < second[index2]) {
            arr[mainIndex++] = first[index1++];
        }
        else{
            arr[mainIndex++] = second[index2++];
        }
    }   

    while(index1 < l1) {
        arr[mainIndex++] = first[index1++];
    }

    while(index2 < l2 ) {
        arr[mainIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int *arr, int l, int r){
    if( l >= r) return;
    
    int mid = l + (r - l)/2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, r);
}

int main(){

    int n;
    cin >> n;

    int *arr = new int[n];

    for(int i=0; i < n; i++){
        cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);

    for(int i=0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}