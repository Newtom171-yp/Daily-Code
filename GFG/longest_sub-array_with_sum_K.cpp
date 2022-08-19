class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int sum = 0, maxLen = 0;
        unordered_map <int,int> m;
        
        for(int i = 0; i < N; i++)
        {
            sum += A[i];
            if(sum == K) maxLen = i+1;
            if(m.find(sum) == m.end()) m[sum] = i;
            if(m.find(sum - K) != m.end())
            {
                int index = m[sum-K];
                maxLen = max(maxLen, i-index);
            }
        }
        return maxLen;
    }
};