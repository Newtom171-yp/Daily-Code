#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector <unsigned long long int> a, unsigned long long int mid, unsigned long long int m){
    unsigned long long int woodSum = 0;
    for(auto i : a){
        if(mid < i){
            woodSum += (i - mid);
        }
    }
    if(woodSum >=m) return true;
    else return false;
}

int main(){
    unsigned long long int n, m, k;
    vector<unsigned long long int> a;
    cin >> n >> m;
    for(unsigned long long int i = 0; i < n; i++){
        cin >> k;
        a.push_back(k);
    }
    unsigned long long int maxi = -1;
    for(unsigned long long int i = 0; i < a.size(); i++){
        maxi = max(a[i], maxi);
    }
    unsigned long long int l = 0;
    unsigned long long int r = maxi;
    unsigned long long int mid = l + (r - l)/2;
    unsigned long long int ans = -1;
    while(l <= r){
        if(isPossible(a,mid,m)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
        mid = l + (r - l)/2;
    }
    cout << ans << endl;
}