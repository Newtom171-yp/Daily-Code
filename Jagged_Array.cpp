#include <iostream>
using namespace std;

int main()
{
    int rows;
    cin >> rows;
    
    //allocating memory
    int **arr = new int*[rows];
    for(int i = 0 ; i < rows; i++){
        arr[i] = new int[i + 1];
    }
    
    //reading input
    for (int  i = 0; i < rows; i++){
        for(int j = 0; j < i + 1; j++){
            cin >> arr[i][j];
        }
    }
    
    //printing output
    for (int  i = 0; i < rows; i++){
        for(int j = 0; j < i + 1; j++){
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }
    
    return 0;
}