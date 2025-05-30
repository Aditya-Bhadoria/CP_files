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
ll two(ll x){
    return __builtin_ctz(x); 
}
ll five(ll x){
    ll exponent = 0;
    while (x % 5 == 0 && x) {
        x /= 5;
        exponent++;
    }
    return exponent;
}
ll largestMulti5(ll m, ll e){
    ll comp = pow(5,e);
    while(comp > m){
        comp /= 5;
    }
    ll ans = (m/comp)*comp;
    return ans;
}
ll largestMulti2(ll m, ll e){
    ll comp = pow(2,e);
    while(comp > m){
        comp /= 2;
    }
    ll ans = (m/comp)*comp;
    return ans;
}
ll checkRound(ll x){
    ll exponent = 0;
    while (x % 10 == 0 && x) {
        x /= 10;
        exponent++;
    }
    return exponent;
}
void solve(){
    ll n, m; cin >> n >> m;
    ll mxxzero = 0;
    ll ans = 1;
    for(int two = 0;two<=29;two++){
        for(int f = 0;f<=12;f++){
            ll a = (ll)pow(2,two) * (ll)pow(5,f);
            if(a>m){
                break;
            }
            else{
                ll b = a;
                ll x = 0;
                while(b%10 == 0){
                    x++;
                    b/=10;
                }
                if(mxxzero < x ){
                    ans = a;
                    mxxzero = x;
                }
                if(mxxzero == x){
                    ans = max(ans,a);
                }

            }
        }
    }
    
    ans/=2;
    ans = (m/ans) * ans;
    cout<<ans*n<<endl ;

}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}