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

const ll mod2 = 1e9 + 7;
const ll mod = 998244353;
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
ll MAXL=5*1e5;
vll fact(MAXL+1), invfact(MAXL+1);
void precompute_factorials() {
    fact[0] = 1;
    for (int i=1; i<=MAXL; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }
    invfact[MAXL] = pow(fact[MAXL], mod-2, mod);
    for (int i = MAXL; i >= 1; i--){
        invfact[i-1] = (invfact[i] * i) % mod;
    }
}
ll dpFunc(const vll& counts, int sumOdd) {
    vll dp(sumOdd+1, 0);
    dp[0] = 1;
    for (ll c : counts) {
        vll new_dp = dp; 
        for (int j = 0; j <= sumOdd; j++){
            if(dp[j] != 0 && j + c <= sumOdd) {
                new_dp[j + c] = (new_dp[j + c] + dp[j]) % mod;
            }
        }
        dp = move(new_dp);
    }
    return dp[sumOdd];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    precompute_factorials();
    while (t--) {
        vll c(26);
        ll L = 0;
        for (int i = 0; i < 26; i++){
            cin >> c[i];
            L += c[i];
        }
        ll odd, even;
        if(L % 2 == 0) { odd = L/2; even = L/2; }
        else { odd = (L+1)/2; even = L - odd; }
        vll pos;
        for (int i = 0; i < 26; i++){
            if(c[i] > 0) pos.push_back(c[i]);
        }
        ll ways = dpFunc(pos, odd);
        ll arrange = (fact[odd] * fact[even]) % mod;
        for (int i = 0; i < 26; i++){
            arrange = (arrange * invfact[c[i]]) % mod;
        }
        ll ans = (ways * arrange) % mod;
        cout << ans << "\n";
    }
    return 0;
}