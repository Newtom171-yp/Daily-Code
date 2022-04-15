vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	vector<int> arr;
	int first=0,sec=0;
	while(1)
	{
		if(first == n || sec == m) break;
		if(arr1[first] < arr2[sec]) 
		{
			first++;
		}
		else if (arr1[first] > arr2[sec])
		{
			sec++;
		}
		else
		{
			arr.push_back(arr1[first]);
			first++;
			sec++;
		}
	}
	return arr;
}