int isExists(int n, vector<int> &arr) {
    // Write your code here.
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] <= 2048){
            sum += arr[i];
        }
        if(sum >= 2048){
            return 1;
        }
    }
    return 0;
}
