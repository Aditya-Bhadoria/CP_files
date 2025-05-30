#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<string> g;
bool cmp(int u, int v){
    if(u < v) return g[u][v] == '1';
    return g[u][v] == '0';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        g.resize(n);
        for(int i=0; i<n; i++) cin >> g[i];
        vector<int> p(n);
        for(int i=0; i<n; i++) p[i] = i;
        sort(p.begin(), p.end(), cmp);
        for (int i = 0; i < n; i++) {
            cout << p[i]+1 << " ";
        }
    cout << endl;
    }

    return 0;
}
