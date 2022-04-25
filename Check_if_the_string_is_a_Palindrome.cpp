bool isValid(char ch){
	return ((ch>='a'&&ch<='z') || (ch>='0' && ch<='9'));
}

bool checkPalindrome(string s)
{
	for(int i = 0; i < s.length(); ; i++){
		if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 'a' - 'A';
	}
	int l = 0;
	int r = s.length()-1;
	while(l<=r){
		if(!isValid(s[l])) l++;
		else if(!isValid(s[r])) r--;
		else if(s[l] != s[r]) return false;
		else{
			l++;r--;
		}
	}
	return true;
	
}