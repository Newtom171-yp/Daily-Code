vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;
	int start,end;
	sort(arr.begin(),arr.end());
	for(int i = 0; i < n-2; i++){
		start = i+1;
		end = n-1;
		while(start < end){
			if(arr[i]+arr[start]+arr[end] == K){
				ans.push_back({arr[i],arr[start],arr[end]});
				int temp1 = arr[start];
				int temp2 = arr[end];
				while(start < end && arr[start]==temp1) start++;
				while(start < end && arr[end]==temp2) end--;
			}
			else if (arr[i]+arr[start]+arr[end] < K){
				start++;
			}
			else{
				end--;
			}
		}
		while(i+1 < n && arr[i]==arr[i+1]) i++;
	}
	return ans;
}