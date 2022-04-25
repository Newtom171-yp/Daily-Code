class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        int a[26] = {0};
        for(int i  = 0; i < str.length(); i++){
            a[str[i]-'a']++;
        }
        int maxIndex,max = -1;
        for(int i = 0; i < 26; i++){
            if(a[i] > max){
                maxIndex = i;
                max = a[i];
            }
        }
        return 'a'+ maxIndex;
    }

};