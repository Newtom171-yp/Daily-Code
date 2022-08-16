class Solution{
	public:
	vector<int> FactDigit(int N)
	{
	    // Code here
	    vector<int> ans;
	    
	    vector<int> fact(10);
	    
	    fact[0] = 1;
	    fact[1] = 1;
	    
	    int index;
	    
	    for(int i = 2; i < 10 && fact[i - 1] < INT_MAX; i++)
	    {
	        fact[i] = i*fact[i-1];
	        index = i;
	    }
	    
	    for(int i = index; i > 0; i--)
	    {
	        while(N >= fact[i])
	        {
	            ans.push_back(i);
	            N -= fact[i];
	        }
	    }
	    
	    reverse(ans.begin(), ans.end());
	    
	    return ans;
	}
};