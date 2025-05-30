#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            a.push_back(x);
        }
        int gcd1, gcd2;
        int check = 1;
        for(int i=0; i<n; i++){
            vector <int> v = a;
            v.erase(v.begin() + i);
            check = 1;
            for(int i=0; i<n-2; i++){
                int gcd1 = gcd(a[i],a[i+1]);
                int gcd2 = gcd(a[i+1],a[i+2]);
                if(gcd1 > gcd2){
                    check = 0;
                    break;
                }
            }
            if(check == 1){
                cout << "YES" << endl;
                break;
            }
            else if(i == n-1 && check == 0){
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}