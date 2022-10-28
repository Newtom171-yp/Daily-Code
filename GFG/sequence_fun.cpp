#define MOD 1000000007
class Solution {
	public:
		long long NthTerm(long long n){
		    if(n == 1) return 2;
		    return (NthTerm(n-1) * n + 1)%MOD; 
		}
};