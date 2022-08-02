class Solution 
{
public:
    int minimumOperations(vector<int>& nums) 
    {
        set<int> s;
        
        for(auto &i : nums)
        {
            if(i) s.insert(i);
        }
        return s.size();
    }
};