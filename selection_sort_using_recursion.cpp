#include <iostream>
using namespace std;

void sort(int *arr, int size){
    
    if(size < 2) return;
    
    int minIndex = 0;
    for(int i = 0; i < size ; i++){
        if(arr[minIndex] > arr[i]) minIndex = i;
    }
    swap(*arr,*(arr + minIndex));
    sort(++arr, --size);
}

int main(){
    
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<< " ";
    }
    return 0;
}