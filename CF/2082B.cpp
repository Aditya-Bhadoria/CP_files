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
int max(int x, int n, int m){
    int count = 0;
    while(x && count < m){
        x = (x+1)/2;
        count++;
        if(x<2){
            break;
        }
    }
    count = 0;
    while(x && count < n){
        x = x/2;
        count++;
        if(!x){
            return 0;
        }
    }
    return x;
}
int min(int x, int n, int m){
    int i=0, j=0;
    int count = 0;
    while(x && count < n){
        x = x/2;
        count++;
        if(!x){
            return 0;
        }
    }
    count = 0;
    while(x && count < m ){
        x = (x+1)/2;
        count++;
        if(x<2){
            break;
        }
    }
    return x;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int x, n, m;
        cin >> x >> n >> m;
        int x1 = min(x, n, m);
        int x2 = max(x, n, m);
        cout << x2 << " " << x1 << "\n";
    }
    return 0;
}