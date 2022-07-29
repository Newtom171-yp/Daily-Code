//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool prime(int n)
    {
        if (n <= 1)
        return false;

        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;
 
        return true;
    }
    
    int dfs(vector<int> &arr, int rank, vector<int> &dp)
    {
        if(!arr[rank-1]) return 0;
        
        if(dp[rank] != -1) return dp[rank];
        
        int senior = arr[rank-1];
        
        return dp[rank] = 1 + dfs(arr,senior,dp);
    }
    
    int firingEmployees(vector<int> &arr, int n){
        // code here
        int cnt = 0;
        vector<int> dp(n+1,-1);
        for(int i = 1; i <= n; i++)
        {
            int senior = dfs(arr,i,dp);
            if(!senior) continue;
            if(prime(senior + i)) cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n,0);
        
        for(int i=0; i<n; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.firingEmployees(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends