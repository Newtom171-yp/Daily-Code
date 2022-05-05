int solve(int *input, int start, int end, int key){
    if(start > end) return -1;
    int mid = start + (end - start)/2;
    if(*(input+mid) == key) return mid;
    if(key > *(input+mid)) return solve(input, mid + 1, end, key);
    else return solve(input, start, mid - 1, key);
    return -1;
}

int binarySearch(int *input, int n, int val)
{
    return solve(input,0,n-1,val);
}