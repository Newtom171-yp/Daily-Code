class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        if(n&1) return false;
        
        unordered_map<int,int> freq;
        
        for(int i = 0; i < n; i++)
        {
            freq[((nums[i] % k) + k) % k]++;
        }
        
        for(int i = 0; i < n; i++)
        {
            int rem = ((nums[i] % k) + k) % k;
            
            if(2 * rem == k) 
            {
                if(freq[rem] & 1)
                return false;
                
            }
            
            else if (!rem) 
            {
                if(freq[rem] & 1)
                return false;
            }
            
            else if(freq[rem] != freq[k - rem]) return false;
        }
        
        return true;
    }
};