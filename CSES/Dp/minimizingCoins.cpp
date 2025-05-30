#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;
using ll = long long;
using ull=unsigned long long;

#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define pb push_back
#define out(v) for(auto i: v) cout<<i<<" ";

const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
typedef tree<int, null_type,less<>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
//p.find_by_order - value at given index
//p.order_of_key - index of given key

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a*b/gcd(a,b); }

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
ll minCoin(vll &x, int n, vll &dp, int t){
    if(t == 0) return 0;
    if(t < 0) return 1e9;
    if(dp[t] != -1) return dp[t];
    
    ll mini = 1e9;
    for(int i=0; i<n; i++){
        mini = min(mini, 1 + minCoin(x, n, dp, t-x[i]));
    }
    return dp[t] = mini;
}
ll minCoinTab(vll &x, int n, int t){
    vll dp1(t+1, 1e9);
    dp1[0] = 0;
    for(int i=1; i<= t; i++){
        for(int j=0; j<n; j++){
            if(i >= x[j]) dp1[i] = min(dp1[i], 1 + dp1[i-x[j]]);
        }
    }
    return (dp1[t] >= 1e9 ? -1 : dp1[t]);
}
vll dp(1e6 + 4, -1);

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, t; cin >> n >> t;
    vll x(n);
    for(int i = 0; i<n; i++){
        cin >> x[i];
    }
    // ll ans = minCoin(x, n, dp, t);
    ll ans = minCoinTab(x, n, t);
    cout << (ans >= 1e9 ? -1 : ans);
    return 0;
}