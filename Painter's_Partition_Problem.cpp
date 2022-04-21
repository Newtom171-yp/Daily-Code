bool isPossible(vector<int>a, int mid, int k){
	int lengthSum = 0;
	int painterCount = 1;
	for(int i = 0; i < a.size(); i++){
		if(lengthSum + a[i] <= mid){
			lengthSum+=a[i];
		}
		else{
			painterCount++;
			if(painterCount > k || a[i] > mid) return false;
			lengthSum = a[i];
		}
	}
	return true;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    int l = 0;
	int sum = 0;
	for(int i : boards){
		sum+=i;
	}
	int r = sum;
	int ans = -1;
	int mid = l + (r - l)/2;
	while(l<=r){
		if(isPossible(boards, mid, k)){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
		mid = l + (r - l)/2;
	}
	return ans;
}