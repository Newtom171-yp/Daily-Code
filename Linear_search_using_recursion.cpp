#include <iostream>
using namespace std;

bool linearSearch(int *arr, int size, int key){
    if(!size) return false;
    if(*arr == key) return true;
    return linearSearch(++arr, --size, key);
}

int main(){
    int n, key;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> *(arr + i);
    }
    cout<<"Enter the key : "<<endl;
    cin >> key;
    cout<<(linearSearch(arr, n, key)?"true":"false");
    return 0;
}