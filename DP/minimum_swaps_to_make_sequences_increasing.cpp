class Solution {
public:
    
    int solve(vector<int> & nums1, vector<int> & nums2, int index, bool swapped)
    {
        //base
        if(index == nums1.size()) return 0;
        
        int ans = INT_MAX;
        
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        
        if(swapped) swap(prev1, prev2);
        
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1, nums2,  index+1, false);
        
        if(nums1[index] > prev2 && nums2[index] > prev1)
            ans = min (ans , 1 + solve(nums1, nums2, index+1, true));
        
        return ans;
        
    }
    
    int solveMem(vector<int> & nums1, vector<int> & nums2, int index, bool swapped, vector<vector<int>> &dp)
    {
        //base
        if(index == nums1.size()) return 0;
        
        int ans = INT_MAX;
        
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        
        if(dp[index][swapped] != -1) return dp[index][swapped];
        
        if(swapped) swap(prev1, prev2);
        
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solveMem(nums1, nums2,  index+1, false, dp);
        
        if(nums1[index] > prev2 && nums2[index] > prev1)
            ans = min (ans , 1 + solveMem(nums1, nums2, index+1, true, dp));
        
        return dp[index][swapped] = ans;
        
    }
    
    int solveTab(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(2,0));
        
        for(int index = n-1; index >= 1; index--)
        {
            for(int swapped = 1; swapped >= 0; swapped--)
            {
                int ans = INT_MAX;
        
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                if(swapped) swap(prev1, prev2);

                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index+1][false];

                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min (ans , 1 + dp[index+1][true]);

                dp[index][swapped] = ans;
            }
        }
        
        return dp[1][false];
    }
    
    int solveOpt(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        
        int swap = 0;
        int  noSwap = 0;
        int currSwap, currNoSwap;
        
        for(int index = n-1; index >= 1; index--)
        {
            for(int swapped = 1; swapped >= 0; swapped--)
            {
                int ans = INT_MAX;
        
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                if(swapped)
                {
                    int temp = prev2;
                    prev2 = prev1;
                    prev1 = temp;
                }
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = noSwap;

                if(nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min (ans , 1 + swap);
                
                if(swapped)
                    currSwap = ans;
                else
                    currNoSwap = ans;
            }
            swap = currSwap;
            noSwap = currNoSwap;
        }
        
        return min(swap,noSwap);
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //If the previous indexes were swapped.
        
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        
        bool swapped = false;
        
        // return solve(nums1, nums2, 1, swapped);
        
        vector<vector<int>> dp(nums1.size()+2, vector<int>(2,-1));
        // return solveMem(nums1, nums2, 1, swapped, dp);
        
        // return solveTab(nums1, nums2);
        
        return solveOpt(nums1, nums2);
    }
};