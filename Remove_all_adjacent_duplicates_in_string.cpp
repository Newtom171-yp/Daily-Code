class Solution {
public:
    string removeDuplicates(string s) {
        int i=0;
    while(i<s.size()){
        if( i+1<s.size() && s[i]==s[i+1]){
            s.erase(i,2);
            if(i>0) i--;
        }else i++;
    }
    return s;
}

};