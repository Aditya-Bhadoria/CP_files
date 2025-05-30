#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll k = 2;
        vector<ll> v(n);
        for(int i=0; i<n; i++){
            cin >> v[n];
        }
        while(1){
            set <ll> rem;
            for(int i=0; i<n; i++){
                rem.insert(v[i]%k);
            }
            if(rem.size() == 2)
                break;
            k*= 2;
        }
        cout << k << endl;
    }
    return 0;
}