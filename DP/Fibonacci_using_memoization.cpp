#include<iostream>
using namespace std;

int solve(int n, int *arr){
    if(n<2) return n;
    
    if(arr[n] > -1) return arr[n];
    
    arr[n] = solve(n-1,arr) + solve(n-2,arr);
    return arr[n];
}

int main(){
    //Write your code here.
    int n;
    cin >> n;
    
    int *arr = new int[n];
    
    for(int i = 0; i<=n; i++){
        arr[i] = -1;
    }
    
    cout << solve(n,arr);
}
