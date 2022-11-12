class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		    
		    int max_freq = 0, max_len = 0, start = 0, end = 0;
		    
		    unordered_map<char,int> m;
		    
		    while(end < s.length())
		    {
		        char curr = s[end];
		        m[curr]++;
		        max_freq = max(max_freq, m[s[end]]);
		        if(end - start + 1 - max_freq > k)
		        {
		            char start_char = s[start];
		            m[start_char]--;
		            start++;
		        }
		        max_len = max(max_len, end - start + 1);
		        end++;
		    }
		    
		    return max_len;
		    
		}

};