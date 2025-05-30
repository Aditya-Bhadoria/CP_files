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
        int n, m;
        cin >> n >> m;
        ll a[n];
        priority_queue<ll> p;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a , a + n);
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            p.push(x);
        }
        int check = 1;
        while (!p.empty()) {
            if (p.size() > n) {
                check = 0; break;
            }
            int h = p.top();
            p.pop();
            if (h < a[n-1]) {
                check = 0; break;
            }
            if (h == a[n-1]) {
                n--;
            } 
            else if (h > a[n-1]) {
                p.push(h / 2);
                p.push(h - h / 2);
            }
        }
        if(check == 0){
            cout << "NO" << '\n';
        }
        else if (p.empty() && n == 0) {
            cout << "YES" << '\n';
        } 
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}