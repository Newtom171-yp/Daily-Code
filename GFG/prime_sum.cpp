class Solution {
public:

    bool is_prime(int n)
    {
        for(int i = 2; i*i <=n; i++)
        {
            if(n%i == 0) 
                return false;
        }
        
        return true;
    }
    
    string isSumOfTwo(int N){
        // code here
        for(int i = 2; i*2 <= N; i++)
        {
            if(is_prime(i)&&is_prime(N-i))
            {
                return "Yes";
            }
        }
        return "No";
    }
};