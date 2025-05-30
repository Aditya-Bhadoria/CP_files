#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<ll>
#define vint vector<int>
#define pb push_back
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;

ll pow(ll a, ll b, ll c) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return ans;
}

void factorial(long long p,ll MAXN, vector<ll> &fac) {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % p; }
}

/**
 * Precomputes all modular inverse factorials
 * from 0 to MAXN in O(n + log p) time
 */
void inverses(long long p,ll MAXN, vector<ll> &inv, vector<ll> &fac) {
	inv[MAXN] = pow(fac[MAXN], p - 2, p);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % p; }
}

/** return nCr mod p */
long long choose(long long n, long long r, long long p, vector<ll> &fac, vector<ll> &inv) {
    if(r > n) return 0;
	return fac[n] * inv[r] % p * inv[n-r]%p;

}
ll MAXN=2*1e5 + 5;
vll fac (MAXN);
vll inv (MAXN);
int main() {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    factorial(mod,MAXN,fac);
    inverses( mod, MAXN, inv , fac);
    while (t--) {
        ll n,k;
        cin >> n >> k ;
        vint v(n);
        ll one=0,zero=0;
        for(int i = 0; i < n ; i++){
            cin >> v[i];
            if(v[i]) one++;
            else zero++;
        }

        ll r=k;
        ll r2=0;
        ll uplim=(k/2)+1;
        ll ans=0;
        while(r>=uplim){
            ll part1=choose(one,r,mod,fac,inv);
            ll part2= choose(zero,k-r,mod,fac,inv);
            ans+=(((part1%mod)*(part2%mod))%mod);
            ans %= mod;
            r--;
        }
        cout << ans%mod << endl;
    }
    return 0;
}