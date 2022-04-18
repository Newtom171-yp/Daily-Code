int binarySearch(vector<int> a, int start, int end, int k){
     int l = start,r = end;
     int mid = l + (r - l)/2;
     while(l <= r){
         if(a[mid] == k){
             return mid;
         }
         if(a[mid] > k){
             r = mid - 1;
         }
         else{
             l = mid + 1;
         }
         mid = l + (r - l)/2;
     }
     return -1;
}

int pivot(vector<int> a, int size){
    int l = 0;
    int r = size - 1;
    int mid = l + (r - l)/2;
    while(l<r){
        if(a[mid]>=a[0]){
            l = mid + 1;
        }
        else{
            r = mid;
        }
        mid = l + (r - l)/2;
    }
    return r;
}

int findPosition(vector<int>& arr, int n, int k)
{
	if(k >= arr[pivot(arr, n)] && k <= arr[n-1]){
		return binarySearch(arr, pivot(arr,n), n - 1, k);
	}
	else{
		return binarySearch(arr, 0, pivot(arr,n), k);
	}
}

