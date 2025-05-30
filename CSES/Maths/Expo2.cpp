#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
ll pow(ll a, ll b, ll c) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        ll a,b,c; cin>>a>>b>>c;
        if(!b && !c){cout<<a<<'\n';} 
        else if(!a && !b){cout<<"1\n";}
        else{cout<<pow(a,pow(b,c,mod-1),mod)<<'\n';}
    }
    return 0;
}