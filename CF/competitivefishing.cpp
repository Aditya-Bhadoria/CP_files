#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull=unsigned long long;
#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define pb push_back
#define out(v) for(auto i: v) cout<<i<<" ";

const ll mod = 1e9 + 7;
const ll mod2 = 998244353;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll pow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}

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
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vll sum;
        ll point=0;
        n--;
        while(n>0){
            if(s[n]=='1') point++;
            else point--;
            sum.push_back(point);
            n--;
        }
        sort(sum.rbegin(),sum.rend());
        int ans=0;
        int i=0;
        while(i<sum.size()){
            ans+=sum[i];
            // cout<<ans<<endl;
            if(ans>=k) break;
            i++;
        }
        if(ans>=k) cout<<i+2<<endl;
        else cout<<"-1"<<endl;

    }
    return 0;
}