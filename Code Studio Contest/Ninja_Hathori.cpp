string ninjaHathori(string s) {
    // Write your code here
    string ans = "";
    ans.push_back(s[0]);
    ans.push_back(s[1]);
    
    for(int i = 3; i < s.length(); i = i + 2)
    {
        ans.push_back(s[i]);
    }
    return ans;
}
