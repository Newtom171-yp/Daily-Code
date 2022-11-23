class Solution {
  public:
    long long int maxSumLCM(int n) 
    {
        // code here
        long long sum = 0;
        for(int i = 1; i*i <= n; i++)
        {
            if(n % i == 0 && i != n/i)
            {
                sum = sum + i + (n/i);
            }
            
            if(n % i == 0 && i == n/i)
            {
                sum = sum + i;
            }
        }
        
        return sum;
    }
};