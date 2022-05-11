class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long *arr, long long l , long long r){
    
    long long invCount = 0;
    
    long long mid = l + (r - l)/2;
    
    long long l1 = mid - l + 1;
    
    long long l2 = r - mid;
    
    long long *first = new long long[l1];
    long long *second = new long long[l2];
    
    long long mainIndex = l;
    
    for(long long i = 0; i < l1; i++) first[i] = arr[mainIndex++];
    
    mainIndex = mid + 1;
    
    for(long long i = 0; i < l2; i++) second[i] = arr[mainIndex++];
    
    long long index1 = 0, index2 = 0;
    
    mainIndex = l;
    
    while(index1 < l1 && index2 < l2){
        if(first[index1] > second[index2]) {
            arr[mainIndex++] = second[index2++];
            invCount += (l1 - index1);
        }
        else arr[mainIndex++] = first[index1++];
    }
    
    while(index1 < l1) arr[mainIndex++] = first[index1++];
        
    while(index2 < l2) arr[mainIndex++] = second[index2++];
    
    delete []first;
    delete []second;
    
    return invCount;
}

long long int mergeSort(long long *arr, long long l, long long r){
    
    long long invCount = 0;
    if(l >= r) return invCount;
    long long mid = l + (r - l)/2;
    
    invCount += mergeSort(arr, l, mid);
    
    invCount += mergeSort(arr, mid+1, r);
    
    invCount += merge(arr, l, r);
    
    return invCount;
    
}

long long int inversionCount(long long arr[], long long N)
{
   return mergeSort(arr, 0, N - 1);
}

};