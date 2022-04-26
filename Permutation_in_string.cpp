class Solution {
public:
    bool check(int a[], int b[]){
        for(int i = 0; i < 26; i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int f1[26] = {0};
        for(int i = 0; i < s1.length(); i++){
            f1[s1[i] - 'a']++;
        }
        
        int window = s1.length();
        int i = 0;
        int f2[26] = {0};
        
        while(i < window && i < s2.length()){
            f2[s2[i]-'a']++;
            i++;
        }
        
        if(check(f1,f2)) return true;
        
        while(i < s2.length()){
            f2[s2[i]-'a']++;
            f2[s2[i-window]-'a']--;
            i++;
            if(check(f1,f2)) return true;
        }
        return false;
    }
};