class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        vector<long long> v;
        long long ans = 0;
        
        for(long long i = 0; i < N; i++)
        {
            ans ^= Arr[i];
        }
        
        long long set_bit = 1;
        
        for(long long i = 0; i < 32; i++)
        {
            if(ans & (1 << i))
            {
                set_bit = (1 << i);
                break;
            }
        }
        long long first = 0, second = 0;
        
        for(long long i = 0; i < N; i++)
        {
            if(Arr[i] & set_bit) first ^= Arr[i];
            else second ^= Arr[i];
        }
        
        v.push_back(max(first,second));
        v.push_back(min(first,second));
        
        return v;
    }
};