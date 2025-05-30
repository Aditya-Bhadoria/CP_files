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

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vll v(n);
        for(int i=0 ; i<n ; i++){
            v[i]=i+1;
        }
        map<ll,set<ll>>mp;
        for(int i=0; i<m ; i++){
            int a,b;
            cin>>a>>b;
            if(a>b) swap(a,b);
            mp[b].insert(a);
        }
        ll cnt=0;
        int lo=0,hi=0;
        set<ll> use;
        while(hi<n){
            if(lo==hi){
                cnt++;
                use.insert(v[hi]);
                hi++;
            }
            else if(mp.find(v[hi])==mp.end()){
                cnt+=(hi-lo+1);
                hi++;
            }
            else if(*prev(mp[v[hi]].end()) < lo){
                cnt += (hi-lo+1);
                hi++;
            }
            else{
                lo = *prev(mp[v[hi]].end());
                cnt += (hi-lo+1);
                hi++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}