#include <iostream>
using namespace std;

bool binarySearch(int *start, int *end, int key){
    if(start > end) return false;
    int *mid = start + (end - start)/2;
    if(*mid == key) return true;
    if(key > *mid) return binarySearch(mid + 1, end, key);
    else return binarySearch(start, mid - 1, key);
    return false;
}

int main(){
    int n, key;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> *(arr + i);
    }
    cin >> key;
    cout<<(binarySearch(arr, arr+n-1, key)?"true":"false");
    return 0;
}