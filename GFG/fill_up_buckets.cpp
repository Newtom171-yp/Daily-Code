class Solution{
public:
    int totalWays(int n, vector<int>capacity) {
        // code here
        sort(capacity.begin(), capacity.end());
        long long ans = 1;
        
        long long mod = 1000000007;
        
        for(int i = 0; i < n; i++)
        {
            ans = ans * (capacity[i]-i)%mod;
        }
        return ans;
    }
};