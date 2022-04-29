class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        
        bool isNotPrime[5000000]={0};
        
        for(int i = 2; i*i < n; i++){
            if(isNotPrime[i]) continue;
            for(int j = i*i; j < n; j+=i){
                isNotPrime[j] = true;
            }
        }
        
        for(int i = 2; i < n; i++){
            if(!isNotPrime[i]) count++;
        }
        return count;
    }
};