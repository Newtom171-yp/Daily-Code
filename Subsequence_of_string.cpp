void subSeq(vector<string> &ans, string str, string s,int index){
	if(index == str.length()){
		if(s.length()) ans.push_back(s);
		return;
	}
	
	//exclusion
	subSeq(ans,str,s,index+1);
		
	//inclusion
	s.push_back(str[index]);
	subSeq(ans,str,s,index+1);
}

vector<string> subsequences(string str){
	vector<string> ans;
	string s;
	subSeq(ans,str,s,0);
	return ans;
}
