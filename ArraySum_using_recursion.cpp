#include <iostream>
using namespace std;

int arrSum(int *arr, int size){
    int sum = 0;
    if(!size) return 0;
    return *arr + arrSum(arr + 1, --size);
}

int main(){
    int n;
    cin >> n;
    int *arr = new int [n];
    for(int i = 0 ; i < n; i++){
        cin >> *(arr + i);
    }

    cout<<arrSum(arr, n)<<"\n";
    return 0;
}