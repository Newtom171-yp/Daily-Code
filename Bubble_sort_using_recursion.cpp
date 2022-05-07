#include <iostream>
using namespace std;

void bubbleSort(int *arr, int size){
    if(size < 1) return;
    int flag = 0;
    for(int i = 0 ; i < size-1; i++){
        if(*(arr+i) > *(arr + i + 1)) {
            swap(*(arr+i) , *(arr + i + 1));
            flag = 1;
        }
    }
    if (!flag) return;
    bubbleSort(arr, size - 1);
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    bubbleSort(arr, n);
    for(int i = 0; i < n; i++){
        cout <<arr[i] << " ";
    }
    return 0;
}