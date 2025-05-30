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
        int n; cin >> n;
        vint p(n), d(n);
        map<int, int> mp;
        for(int i=0; i<n; i++){ 
            cin >> p[i]; 
            mp[i+1] = p[i];
        }
        for(int i=0; i<n; i++){ cin >> d[i]; }
        vint ans(n);
        int cnt = 1;
        if(mp[d[0]]==d[0]){
            ans[0]=1;
            mp.erase(d[0]);
        }
        else{
            int a = d[0];
            int cnt=1;
            while(mp.find(mp[a])!=mp.end()){
                int aa=mp[a];
                mp.erase(a);
                a=aa;
                cnt++;
            }
            mp.erase(a);
            ans[0]=cnt;
        }
        for(int i=1; i<n; i++){
            int a = d[i];
            if(mp.find(a)==mp.end()){
                ans[i]=ans[i-1];
            }
            else if(mp[a]==a){
                ans[i]=ans[i-1]+1;
            }
            else{
                int cnt=1;
                while(mp.find(mp[a])!=mp.end()){
                   int aa=mp[a];
                    mp.erase(a);
                    a=aa;
                    cnt++;
                }
                mp.erase(a);
                ans[i]=ans[i-1]+cnt;
            }
        }
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        } cout << endl;
    }
    return 0;
}