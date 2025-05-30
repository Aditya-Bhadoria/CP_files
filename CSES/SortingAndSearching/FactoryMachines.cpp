#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vll vector<ll>
bool isPossible(vll v, ll mid, ll t){
    ll sum = 0;
    for(int i=0; i<v.size(); i++){
        sum += mid/v[i];
        if(sum >= t){
            return true;
        }
    }
    return sum >= t ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, t, fast = INT_MAX; cin >> n >> t;
    vll v(n); for(int i=0; i<n; i++){ cin >> v[i]; fast = min(fast, v[i]); }
    ll lo = 1, hi = fast*t;
    ll mid = lo + (hi-lo)/2;
    while(hi-lo>1){
        if(isPossible(v, mid, t)){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
        mid = lo + (hi-lo)/2;
    }
    if(isPossible(v, lo, t)){
        cout << lo << endl;
    }
    else{
        cout << hi << endl;
    }
    return 0;
}