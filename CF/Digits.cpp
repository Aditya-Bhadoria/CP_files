#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

void check(bool b) {
    if (b)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x,d;
        cin>>x>>d;
        set<int> s;
        s.insert(1);
        if(d%3==0||x>2) s.insert(3);
        if(d%9==0||x>5) s.insert(9);
        if(d==3||d==6){
            if(x>2) s.insert(9);
        }
        if(d%5==0) s.insert(5);
        if((d%7==0)||(x>=3)) s.insert(7);
        // if((x*(d)-d)%7==0) s.insert(7);
        for(auto it:s){
            cout<<it<<" ";
        }cout<<endl;
    }
    return 0;
}