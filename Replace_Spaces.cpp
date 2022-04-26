string replaceSpaces(string &str){
	for(int i = 0; i < str.length(); i++){
		if(str[i] == ' '){
			str.replace(i,1,"@40");
		}
	}
	return str;
}