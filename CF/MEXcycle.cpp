#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;

// Function to calculate modular exponentiation
ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Precomputing factorials and inverse factorials for combinatorics
    vector<ll> fact(n + 1, 1), inv_fact(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    for (int i = 0; i <= n; i++) {
        inv_fact[i] = mod_exp(fact[i], MOD - 2, MOD);
    }

    auto nCr = [&](int x, int y) -> ll {
        if (x < y || y < 0) return 0;
        return fact[x] * inv_fact[y] % MOD * inv_fact[x - y] % MOD;
    };

    ll result = 0;

    // Iterating over all subsets
    for (int mask = 0; mask < (1 << n); mask++) {
        ll sum = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += a[i];
                cnt++;
            }
        }
        if (sum == m) {
            result = (result + nCr(n, cnt)) % MOD;
        }
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
