#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll __gcd(ll a, ll b) {
    return b ? __gcd(b, a % b) : a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll l, r, G;
        cin >> l >> r >> G;

        if (r < G) {
            cout << "-1 -1\n";
            continue;
        }

        ll k1_min = (l + G - 1) / G;
        ll k1_max = r / G;

        if (k1_min == k1_max) {
            cout << k1_min << " " << k1_min << endl;
            continue;
        }
        else if(__gcd(k1_min, k1_max) == 1){
            cout << k1_min << " " << k1_max << endl;
            continue;
        }

        ll k1 = k1_min;
        ll k2 = k1_min + 1;

        while (k2 <= k1_max && __gcd(k1, k2) != 1) {
            k2++;
        }

        if (k2 <= k1_max) {
            cout << G * k1 << " " << G * k2 << "\n";
        } else {
            cout << "-1 -1\n";
        }
    }

    return 0;
}
