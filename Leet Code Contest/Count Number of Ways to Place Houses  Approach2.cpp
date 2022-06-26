class Solution {
public:
    int countHousePlacements(int n) {
        
        int prev0 = 1;
        int prev1 = 1;
        
        int count0;
        int count1;
        
        for(int i = 2; i <= n; i++)
        {
            count0 = prev1;
            count1 = prev1%1000000007 + prev0%1000000007;
            
            prev1 = count1;
            prev0 = count0;
        }
        
        long long final = prev1%1000000007 + prev0%1000000007;
        
        final = final%1000000007 * final%1000000007;
        return final;
        
    }
};