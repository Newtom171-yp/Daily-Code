#include<iostream>
using namespace std;

int main(){
    //Write your code here.
    int n;
    cin >> n;
    
    int *arr = new int[n];
    
    int prev1 = 0;
    int prev2 = 1;
    int curr;
    for(int i = 2; i <= n; i++){
     curr = prev1 + prev2;
     prev1 = prev2;
     prev2 = curr;
    }
    if(n < 2) curr = n;
    cout << curr <<endl;
    return 0;
}
