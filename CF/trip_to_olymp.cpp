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
        ll l,r;
        cin>>l>>r;
        bitset<32>lll(l);
        bitset<32>rr(r);
        int i=31;
        ll num=0;
        while(lll[i]==rr[i]){
            if(lll[i])num+=(1LL<<i);
            i--;
        }
        num+=(1LL<<i);
        ll num2=num-1;
        cout<<num<<" "<<num2<<" ";
        ll num3=l;
        while((num3==num2)||(num3==num)){
            num3++;
        }
        cout<<num3<<endl;
    }
    return 0;
}