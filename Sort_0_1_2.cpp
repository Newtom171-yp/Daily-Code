void sort012(int *arr, int n)
{
	int l=0;
	int m=0;
	int r=n-1;
	while(m <= r){
		if(!arr[m]){
			swap(arr[l],arr[m]);
			l++;m++;
		}
		else if(arr[m]==1) m++;
		else{
			swap(arr[m],arr[r]);
			r--;
		}
	}
}