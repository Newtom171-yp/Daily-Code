class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int lsum = 0;
        for(auto i : nums){
            sum+=i;
        }
        for(int i = 0; i < nums.size(); i++){
            if(lsum == sum - lsum - nums[i]) return i;
            lsum+=nums[i];
        }
        return -1;
    }
};