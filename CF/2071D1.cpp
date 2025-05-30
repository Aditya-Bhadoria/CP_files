#include <bits/stdc++.h>
using namespace std;

int computeXorUpToK(const vector<int>& a, long long k) {
    int xorResult = 0;
    for (long long i = 0; i < k && i < a.size(); ++i) {
        xorResult ^= a[i];
    }
    return xorResult;
}

// Function to compute a_l for l > n
int computeAl(const vector<int>& a, long long l) {
    while (l > a.size()) {
        l = l / 2;
    }
    return a[l - 1];
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long l, r;
        cin >> n >> l >> r;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (l == r) {
            if (l <= n) {
                cout << a[l - 1] << "\n";
            } else {
                cout << computeAl(a, l) << "\n";
            }
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}