#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n,k; cin >> n >> k;
        int a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        int s = 0, e = n-1, ans = 0;
        while(e>s){
            if(a[e] + a[s] > k){
                e--;
            }
            else if(a[e] + a[s] < k){
                s++;
            }
            else{
                ans++;
                s++; e--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}