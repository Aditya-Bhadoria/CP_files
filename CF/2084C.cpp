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
#define pii pair<int, int>
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
        vll a(n+1),b(n+1);
        for(int i=1 ; i<=n ; i++){ 
            cin>>a[i];
        }
        for(int i=1 ; i<=n ; i++){ 
            cin>>b[i];
        }
        int same=0;
        int samepos=-1;
        map<ll,ll> mpa;
        map<ll,ll> ind;
        for(int i=1 ; i<=n ; i++){
            if(a[i]==b[i]){
                same++;
                samepos=i;
            }
        }
        vector<pii> ops;
        if(same>1){
            cout<<-1<<endl;
            continue;  
        }
        if(same==1){
            if(n&1){
                if(samepos!=(n/2+1)) ops.push_back({n/2+1,samepos});
                swap(a[samepos],a[n/2+1]);
                swap(b[samepos],b[n/2+1]);
            }
            else{
                cout<<-1<<endl;
                continue;
            }
        }
        for(int i=1 ; i<=n ; i++){
            mpa[a[i]]=b[i];
            ind[a[i]]=i;
        }
        int check = 1;
        for(auto [x,y]:mpa){
            if(mpa[y]!=x){
                cout<<-1<<endl;
                check = 0;
                break;
            }
        }
        if(!check) continue;
        
        int lo = 1, hi = n;
        while(lo < hi){
            if(a[lo] == b[hi]){
                lo++;
                hi--;
            } else {
                ll num = ind[b[hi]];
                ops.push_back({num, lo});
                swap(a[lo], a[num]);
                swap(b[lo], b[num]);
                ind[a[num]] = num;
                ind[a[lo]] = lo;
                lo++;
                hi--;
            }
        }
        cout<<ops.size()<<endl;
        for(auto [x,y]:ops){
            cout<<x<<" "<<y<<endl;
        }
    }
    return 0;
}