class Solution {
public:
    int bitwiseComplement(int n) {
        if (!n) return 1;
        int x = n;
        int mask = 0;
        while(x){
            x = x >> 1;
            mask = (mask << 1) | 1;
        }
        int ans = (~n) & mask;
        return ans;
    }
};