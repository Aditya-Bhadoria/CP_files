#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define N cout<<endl
#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull>
bool isPossible(vll v, ll mid, ll k){
    ll sum = 0, count = 1;
    for(int i=0; i<v.size(); i++){
        if(sum + v[i] <= mid){
            sum += v[i];
        }
        else{
            count++;
            if(count > k || v[i] > mid){
                return false;
            }
            sum = v[i];
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    ll hi = 0, lo = 0;
    vll v(n); for(int i=0; i<n; i++){ cin >> v[i]; hi += v[i]; }
    ll mid = lo + (hi-lo)/2;
    while(hi-lo>1){
        if(isPossible(v, mid, k)){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
        mid = lo + (hi-lo)/2;
    }
    cout << (isPossible(v, lo, k) ? lo : hi);
    return 0;
}