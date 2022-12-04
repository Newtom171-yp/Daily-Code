class Solution{
    public:
    
    void solve(vector<int> &a,vector<int> &b, string &s)
    {
        int p=0,q=0;
        for(int i=0;i<s.length();i++){
            if(i%2==0){
                while(a[p]==0)
                    p++;
                s[i]= p+'a';
                a[p]--;
            }
            else{
                while(b[q]==0)
                    q++;
                s[i] = q+'a';
                b[q]--;
            }
        }
    }
    
    string rearrange (string S, int N)
    {
        // your code here
        int vowel = 0, consonant = 0;
        vector<int> v_count(26,0);
        vector<int> c_count(26,0);
        for(int i = 0; i < N; i++)
        {
            if(S[i] == 'u' || S[i] == 'o' || S[i] == 'i' || S[i] == 'e' || S[i] == 'a') 
            {
                vowel++;
                v_count[S[i] - 'a']++;
            }
            else 
            {
                consonant++;
                c_count[S[i] - 'a']++;
            }
        }
        
        if(abs(vowel-consonant) > 1) return "-1";
        
        if(vowel > consonant) solve(v_count, c_count, S);
        if(consonant > vowel) solve(c_count, v_count, S);
        
        else{
            for(int i=0;i<26;i++){
                if(c_count[i]>0){
                    solve(c_count , v_count , S);
                    break;
                }
                if(v_count[i]>0){
                    solve(v_count , c_count , S);
                    break;
                }
            }
        }
        return S;
    }
};