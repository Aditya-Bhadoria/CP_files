#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        v[0] = 1; v[1] = 1; v[2] = 2;
        v[n-1] = 2; v[n-2] = 1;
        for(int i=6; i<=n; i++){
            v[i-3] = i-3;
        }
        for(int i=0; i<n; i++){cout << v[i] << " ";}
        cout << '\n';
    }
    return 0;
}
