//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
    //complete the function here
    
    int n = str.length();
    
    int** arr = new int*[n];
    
    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    
    for(int g = 0; g < n; g++)
    {
        for(int i = 0, j = g; j < n; j++,i++)
        {
            if(!g) arr[i][j] = 1;
            else if(g == 1) arr[i][j] = (str[i] == str[j]) ? 2 : 1;
            else
            {
                if(str[i] == str[j]) arr[i][j] = 2 + arr[i+1][j-1];
                else arr[i][j] = max(arr[i+1][j], arr[i][j-1]);
            }
        }
    }
    
    return n - arr[0][n-1];
    
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends