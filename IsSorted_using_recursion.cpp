#include <iostream>
using namespace std;

bool isSorted(int *arr, int size){
    if(size < 2) return true;
    if(*arr > *(arr + 1)) return false;
    return isSorted(arr+1, --size);
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout<<"The end result: "<<isSorted(arr, n);
    return 0;
}