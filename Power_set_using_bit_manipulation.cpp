class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    int n = s.length();
		    for(int i = 1; i < (1 << n); i++){
		    string str = "";
		        for(int j = 0; j < n; j++){
		            if(i & (1 << j)) str.push_back(s[j]);
		        }
		        ans.push_back(str);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};