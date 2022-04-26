string replaceSpaces(string &str){
	for(int i = 0; i < str.length(); i++){
		if(str[i] == ' '){
			str.erase(i,1);
			str.insert(i,"@40");
		}
	}
	return str;
}