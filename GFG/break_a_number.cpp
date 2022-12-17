class Solution{   
public:
    int waysToBreakNumber(int N){
        // code here 
        long long m = 1000000007;
        return (((((N+1)%m) * ((N+2)%m))%m)/2)%m;
    }
};