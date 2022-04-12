class Solution {
public:
    int digit,n=0;
    int reverse(int x) {
        while(x){
            digit = x % 10;
            if(n < INT_MIN/10 || n > INT_MAX/10) return 0;
            n = n*10 + digit;
            x = x/10;
        }
        return n;
    }
};