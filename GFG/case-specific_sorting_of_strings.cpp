class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string s;
        if(!str.length() || str.length() == 1) return str;
        
        s = str;
        
        sort(str.begin(), str.end());
        
        int lower = 0;
        int upper = 0;
        
        while(str[lower] >= 'A' && str[lower] <= 'Z') lower++;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] >= 'a')
            {
                s[i] = str[lower];
                lower++;
            }
            else
            {
                s[i] = str[upper];
                upper++;
            }
        }
        
        return s;
    }
};