bool isPossible(vector<int> v, int mid, int k){
	int cowCount = 1;
	int lastPos = v[0];
	for(int i = 0; i < v.size(); i++){
		if(v[i] - lastPos >= mid){
			cowCount++;
			if(cowCount == k) return true;
			lastPos = v[i];
		}
		
	}
	return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
	int l = 0;
	sort(stalls.begin(), stalls.end());
	int r = stalls[stalls.size()-1];
	int ans = -1;
	int mid = l + (r - l)/2;
	while(l <= r) {
		if(isPossible(stalls, mid, k)){
			ans = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
		mid = l + (r - l)/2;
	}
	return ans;
}