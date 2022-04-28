class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        
        bool isPrime[5000000]={0};
        
        for(int i = 2; i*i < n; i++){
            if(isPrime[i]) continue;
            for(int j = i*i; j < n; j+=i){
                isPrime[j] = true;
            }
        }
        
        for(int i = 2; i < n; i++){
            if(!isPrime[i]) count++;
        }
        return count;
    }
};