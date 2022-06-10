int SmallerElements(int N, vector<int>&P){
	// Write your code here.
    int count = 0;
    int *arr = new int[P.size()];
    arr[0] = P[0];
    for(int i = 1; i<N; i++){
        (P[i] < arr[i-1]) ? (arr[i] = P[i]) : (arr[i] = arr[i-1]);
    }
    for(int i = 0; i<N; i++){
        if(arr[i]==P[i]) count++;
    }
    return count;
}