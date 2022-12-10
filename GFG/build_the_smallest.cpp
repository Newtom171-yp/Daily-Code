string buildLowestNumber(string num, int k)
{
    //code here.
    stack<char> s;
    
    int n = num.size();
    
    for(int i = 0; i < n; i++)
    {
        char ch = num[i];
        
        while(!s.empty() && s.top() - '0' > ch - '0' && k > 0)
        {
            s.pop();
            k--;
        }
        
        s.push(ch);
    }
    
    while(k > 0 && !s.empty())
    {
        s.pop();
        k--;
    }
    
    string ans = "";
    while(!s.empty())
    {
        char ch = s.top();
        s.pop();
        ans.push_back(ch);
    }
    
    while(ans.back() == '0') ans.pop_back();
    
    if(ans.empty()) return "0";
    
    reverse(ans.begin(), ans.end());
    return ans;
}