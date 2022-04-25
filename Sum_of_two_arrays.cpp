vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	vector<int> ans;
	int carry = 0;
	int i = n - 1, j = m - 1;
	int sum = 0;
	while(i >= 0 && j >= 0){
		sum = a[i] + b[j] + carry;
		ans.push_back(sum%10);
		carry = sum/10;
		i--; j--;
	}
	while(i >= 0){
		sum = a[i] + carry;
		ans.push_back(sum%10);
		carry = sum/10;
		i--;
	}
	while(j >= 0){
		sum = b[j] + carry;
		ans.push_back(sum%10);
		carry = sum/10;
		j--;
	}
	while(carry){
		sum = carry;
		ans.push_back(sum%10);
		carry = sum/10;
	}
	int s = 0;
    int e = ans.size()-1;
    
    while(s<e)
    {
        swap(ans[s++], ans[e--]);
    }
	return ans;
}