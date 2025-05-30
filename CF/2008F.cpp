#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll pow(ll a, ll b, ll c) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return ans;
}
const ll mod = 1e9 + 7;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >>t;
    while(t--){
        ll n; cin >> n;
        ll arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        ll pref[n];
        pref[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            pref[i] = arr[i] + pref[i+1];
        }
        ll num = 0;
        for(int i=0; i<n-1; i++){
            ll sumq = ((arr[i] % mod)*(pref[i+1] % mod))% mod;
            num += sumq;
            // cout << sumq << " ";
        } 
        // cout << num << '\n' ;
        ll denomi= ((n)*(n-1))/2;
        denomi%=mod;
        ll denomii=(pow(denomi,(mod-2),mod));
        ll ans=((num%mod)*(denomii%mod))%mod;
        cout<<ans<<endl;
    }
    return 0;
}