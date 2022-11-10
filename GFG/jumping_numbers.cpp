class Solution {
  public:
    long long jumpingNums(long long X) {
        // code here
        queue<long long> q;
        
        for(long long i = 1; i <= 9; i++)
        {
            q.push(i);
        }
        
        long long ans = 0;
        
        while(!q.empty())
        {
            long long num = q.front();
            q.pop();
            if(num > X) continue;
            
            ans = max(ans,num);
            
            long long last_digit = num%10;
            if(last_digit)
            {
                long long first = num*10 + (last_digit - 1);
                q.push(first);
            }
            if(last_digit != 9)
            {
                long long second = num*10 + (last_digit + 1);
                q.push(second);
            }
        }
        return ans;
    }
};