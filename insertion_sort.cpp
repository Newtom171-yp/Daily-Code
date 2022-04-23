void insertionSort(int n, vector<int> &arr){
    for(int i = 1; i < n; i++){
		int j = i - 1;
		int temp = arr[i];
		while(j >= 0){
			if(temp < arr[j]) arr[j+1] = arr[j];
			else break;
			j--;
		}
		arr[j+1] = temp;
	}
}