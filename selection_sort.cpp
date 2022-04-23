void selectionSort(vector<int>& arr, int n)
{   
    for(int i = 0; i < arr.size(); i++){
		int minIndex = i;
		for(int j = i + 1; j < arr.size(); j++){
			if(arr[minIndex] > arr[j]) minIndex = j;
		}
		swap(arr[i], arr[minIndex]);
	}
}