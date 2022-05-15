int partition(vector<int> &arr, int l, int r){
		int count = 0;
		int pivot = arr[l];
		for(int i = l+1; i <= r; i++){
			if(arr[i] < pivot) count++;
		}
		swap(arr[l],arr[l+count]);
		int pivotIndex = l + count;
		
		int i = l, j = r;
		
		while(i <pivotIndex && j > pivotIndex){
			while(arr[i] < arr[pivotIndex]) i++;
			while(arr[j] > arr[pivotIndex]) j--;
			if(i <pivotIndex && j > pivotIndex){
				swap(arr[i++],arr[j--]);
			}
		}
		return pivotIndex;
}		
void qSort(vector<int> &arr, int l, int r){
		if(l >= r) return;
		
		int p = partition(arr, l, r);
		qSort(arr, l , p-1);
		qSort(arr, p+1, r);
		
}
vector<int> quickSort(vector<int> arr)
{
    // Write your code here.public class Solution {
		qSort(arr, 0, arr.size()-1);
		return arr;
}