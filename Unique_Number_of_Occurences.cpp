class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int m[2001] = {0};
        int n[2001] = {0};
        int ans = 0;
        for(auto i : arr){
            m[1000 + i]++;
        }
        for(auto i : m){
            n[i]++;
        }
        for (int i = 1; i < 2001; i++){
            if(n[i] > 1) return false;
        }
        return true;
    }
};