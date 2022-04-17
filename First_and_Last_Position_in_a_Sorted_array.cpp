pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int , int> p(-1, -1);
	int l = 0;
	int r = n -1;
	int mid = l + (r - l)/2;
	while (l <= r){
		if(arr[mid] == k){
			r = mid - 1;
			p.first = mid;
		}
		else if(arr[mid] < k){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
		mid = l + (r - l)/2;
	}
	l = 0;
	r = n -1;
	mid = l + (r - l)/2;
	while (l <= r){
		if(arr[mid] == k){
			l = mid + 1;
			p.second = mid;
		}
		else if(arr[mid] < k){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
		mid = l + (r - l)/2;
	}
	return p;
}