int isPossibleToMakeEqual(int n, vector<string> &s) {
    // Write your code here.
    int arr[26]={0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < s[i].length(); j++){
            arr[s[i][j] - 'a']++;
        }
    }
    for(auto i : arr){
        if(i%n) return 0;
    }
    return 1;
}
