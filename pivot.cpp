#include <iostream>
using namespace std;

int pivot(int a[], int size){
    int l = 0;
    int r = size - 1;
    int mid = l + (r - l)/2;
    while(l<r){
        if(a[mid]>=arr[0]){
            l = mid + 1;
        }
        else{
            r = mid;
        }
        mid = l + (r - l)/2;
    }
    return r;
}

int main(){
    int arr[] = {3, 8, 10, 17, 1, -1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "The pivot element is at index: "<< pivot(arr, size)<<endl;
}