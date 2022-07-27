//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> q;
        
        for(int i = 0; i < n; i++)
        {
            q.push(arr[i]);
        }
        
        int count = 0;
        while(q.top() < k)
        {
            int num1 = q.top();
            q.pop();
            int num2 = q.top();
            q.pop();
            q.push(num1 + num2);
            count++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends