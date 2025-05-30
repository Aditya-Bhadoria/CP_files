#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        multiset<int> m;
        int a;
        for(int i=0; i<n; i++){
            cin >> a;
            m.insert(a);
        }
        set<int> s;
        auto it = m.begin();
        while(it != m.end()){
            m.insert(*it);
        }
    }
    return 0;
}