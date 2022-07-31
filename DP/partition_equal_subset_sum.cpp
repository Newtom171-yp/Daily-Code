//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool solve(int N, int arr[], int sum, int index)
    {
        
        if(index >= N) return false;
        
        if(sum == 0) return true;
        
        if(sum < 0) return false;
        
        //include 
        
        bool include = solve(N,arr,sum - arr[index], index+1);
        
        //exclude
        
        bool exclude = solve(N,arr,sum, index + 1);
        
        return (include || exclude);
    }
    
    bool solveMem(int N, int arr[], int sum, int index, vector<vector<int>> &dp)
    {
        
        if(index >= N) return false;
        
        if(sum == 0) return true;
        
        if(sum < 0) return false;
        
        //include 
        
        if(dp[index][sum] != -1) return dp[index][sum];
        
        bool include = solveMem(N,arr,sum - arr[index], index+1, dp);
        
        //exclude
        
        bool exclude = solveMem(N,arr,sum, index + 1, dp);
        
        return dp[index][sum] = (include || exclude);
    }
    
    int solveTab(int N ,int arr[], int sum)
    {
        vector<vector<int>> dp (N + 1,vector<int>(sum+1,0));
        
        for(int i = 0; i <= N; i++)
        {
            dp[i][0] = true;
        }
        
        for(int index = N-1; index >= 0; index--)
        {
            for(int target = 0; target<=sum; target++)
            {
                bool include;
                if(target - arr[index] >= 0)
                include = dp[index+1][target - arr[index]];
                
                bool exclude = dp[index+1][target];
                
                dp[index][target] = (include || exclude);
            }
        }
        return dp[0][sum];
    }
    
    int solveOpt(int N ,int arr[], int sum)
    {
        vector<int> curr(sum + 1, 0);
        vector<int> next(sum + 1, 0);
        
        curr[0] = true;
        next[0] = true;
        
        for(int index = N-1; index >= 0; index--)
        {
            for(int target = 0; target<=sum; target++)
            {
                bool include = false;
                if(target - arr[index] >= 0)
                include = next[target - arr[index]];
                
                bool exclude = next[target];
                
                curr[target] = (include || exclude);
            }
            next = curr;
        }
        return next[sum];
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = accumulate(arr , arr + N, 0);
        
        if(sum&1) return false;
        
        sum /= 2;
        
        // return solve(N,arr,sum,0);
        
        // vector<vector<int>> dp (N,vector<int>(sum+1,-1));
        
        // return solveMem(N,arr,sum,0,dp);
        
        // return solveTab(N,arr,sum);
        
        return solveOpt(N,arr,sum);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends