class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int m[100001] = {0};
        vector<int> v;
        for(auto i : nums){
            m[i]++;
        }
        for(int i = 0; i < 100001; i++){
            if(m[i] > 1) {v.push_back(i);}
        }
        return v;
    }
};