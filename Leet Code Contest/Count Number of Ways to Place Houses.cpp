class Solution {
public:
    
    int fib(int n)
    {
    int prev1 = 0;
    int prev2 = 1;
    int curr;
    for(int i = 2; i <= n; i++){
     curr = prev1%(1000000007) + prev2%(1000000007);
     prev1 = prev2%(1000000007);
     prev2 = curr%(1000000007);
    }
    if(n < 2) curr = n%(1000000007);
        return curr%(1000000007);
    }
    
    int countHousePlacements(int n) {
        long long ans = fib(n+2)%(1000000007);
        long long ans2 = (ans%(1000000007))*(ans%(1000000007));
        return ans2%(1000000007);
    }
};