bool isPossible(vector<int> a, int n, int m, int mid){
	int pageSum = 0;
	int studCount = 1;
	for(int i = 0; i < n; i ++){
		if(pageSum + a[i] <= mid){
			pageSum += a[i];
		}
		else{
			studCount++;
			if(studCount > m || mid < a[i]) return false;
			pageSum = a[i];
		}
	}
	return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int l = 0;
	int sum = 0;
	for(int i : arr){
		sum+=i;
	}
	int r = sum;
	int mid = l + (r - l)/2;
	int ans = -1;
	while(l<=r){
		if(isPossible(arr, n, m, mid)){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
		mid = l + (r - l)/2;
	}
	return ans;
}