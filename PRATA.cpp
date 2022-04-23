#include <bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int mid, int n, int prata){

    int prataCount = 0;
    for(int i = 0; i < n; i++){
        int time = mid;
        int rPrataCount = 0;
        int substractor = a[i];
        while(time > 0){
            time -= substractor;
            if(time >= 0){
                rPrataCount++;
                substractor += a[i];
            }
        }
        prataCount += rPrataCount;
        if(prataCount >= prata) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int prata, l;
    int r[50];
    while(t--){
        cin >> prata;
        cin >> l;
        for(int i = 0; i < l; i++){
            cin >> r[i];
        }
        int start = 0;
        int maxi = -1;
        for(int i = 0; i < l; i++){
            maxi = max(r[i], maxi);
        }
        int end = maxi*prata*(prata+1)/2;
        int mid = start + (end - start)/2;
        int ans=-1;
        while(start <= end){
            if (isPossible(r, mid, l, prata)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }
        cout << ans << "\n";
    }
    return 0;
}