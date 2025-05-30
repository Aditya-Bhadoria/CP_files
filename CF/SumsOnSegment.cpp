#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Size of the array

        vector<int> a(n);
        int count1 = 0, countNeg1 = 0;
        int x = 0; // Special element
        bool hasX = false;

        // Count occurrences of 1 and -1, and identify the special element
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 1) {
                count1++;
            } else if (a[i] == -1) {
                countNeg1++;
            } else {
                hasX = true;
                x = a[i];
            }
        }

        // Compute all possible sums without considering x
        set<int> sums;
        sums.insert(0); // Empty subarray sum
        for (int i = -countNeg1; i <= count1; ++i) {
            sums.insert(i);
        }

        // If x exists, consider its effect
        if (hasX) {
            set<int> newSums = sums;
            for (int s : sums) {
                newSums.insert(s + x);
            }
            sums = newSums; // Update the sums with the effect of x
        }

        // Output the results
        cout << sums.size() << endl;
        for (int sum : sums) {
            cout << sum << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
