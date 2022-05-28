class Solution {
private:
    void solve(string digits, vector<string> &ans, string output, string maps[], int index){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        int num = digits[index] - '0';
        string val = maps[num];
        for(int i = 0; i < val.length(); i++){
            output.push_back(val[i]);
            solve(digits, ans, output, maps, index+1);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output;
        string maps[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(!digits.length()) return ans;
        solve(digits,ans,output,maps,0);
        return ans;
    }
};