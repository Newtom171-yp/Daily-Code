class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        long long int mid = l + (r - l)/2;
        int ans;
        while(l <= r){
            if(mid*mid == x) return mid;
            if(mid*mid < x){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
            mid = l + (r - l)/2;
        }
        return ans;
    }
};