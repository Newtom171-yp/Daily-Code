class Solution {
private:
    void powerSet(vector<vector<int>> &ans, vector<int> nums, vector<int> output,int index){
        if(index == nums.size()){
            ans.push_back(output);
            return;
        }
        
        //exclude
        powerSet(ans,nums,output,index+1);
        
        //include
        output.push_back(nums[index]);
        powerSet(ans,nums,output,index+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        powerSet(ans,nums,output,0);
        return ans;
    }
};