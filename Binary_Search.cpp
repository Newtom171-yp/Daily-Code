#include <iostream>
using namespace std;

int binarySearch(int a[], int size, int k){
     int l = 0,r = size - 1;
     int mid = l + (r - l)/2;
     while(l <= r){
         if(a[mid] == k){
             return mid;
         }
         if(a[mid] > k){
             r = mid - 1;
         }
         else{
             l = mid + 1;
         }
         mid = l + (r - l)/2;
     }
     return -1;
}

int main(){
    int even[] = {1, 4, 6, 7, 10, 11, 19, 21};
    int odd[] = {0, 3, 5, 8, 9, 13, 90};
    int evenSize = sizeof(even)/sizeof(even[0]);
    int oddSize = sizeof(odd)/sizeof(odd[0]);
    cout <<"4 is present at : "<<binarySearch(even, evenSize, 4)<<endl;
    cout <<"90 is present at : "<<binarySearch(odd, oddSize, 90)<<endl;    
}

