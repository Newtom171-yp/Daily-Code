class Solution {
public:

    bool possible(int mid, int k, vector<int> &stalls)
    {
        int cowCount = 1;
        
        int lastPos = stalls[0];
        
        for(int i = 1; i < stalls.size(); i++)
        {
            if(stalls[i] - lastPos >= mid)
            {
                cowCount++;
                if(cowCount == k) return true;
                lastPos = stalls[i];
            }
            
            
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        int ans = -1;
        int maxi = INT_MIN;
        // int mini = INT_MAX;
        
        sort(stalls.begin(), stalls.end());
        
        for (int i = 0; i < stalls.size(); i++)
        {
            maxi = max(maxi, stalls[i]);
            // mini = min(mini, stalls[i]);
        }
        
        int s = 0, e = maxi;
        
        int mid = s - (s - e)/2;
        
        while(s <= e)
        {
            if(possible(mid, k, stalls))
            {
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;
            
            mid = s - (s - e)/2;
        }
        
        return ans;
    }
};