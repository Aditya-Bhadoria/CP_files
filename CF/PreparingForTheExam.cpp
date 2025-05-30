#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a;
        vector<int> q;
        for(int i=0; i<m; i++){
            int g; cin >> g;
            a.push_back(g);
        }
        for(int i=0; i<k; i++){
            int g; cin >> g;
            q.push_back(g);
        }
        if(n-k > 1){
            for(int i=0; i<m; i++){
                cout << 0;
            }
            cout << endl;
        }
        else if(n-k == 0){
            for(int i=0; i<m; i++){
                cout << 1;
            }
            cout << endl;
        }
        else{
            int x;
            for(int i=1; i<=n; i++){
                if(i != q[i-1]){
                    x = i;
                    break;
                }
            }
            for(int i=0; i<m; i++){
                if(a[i] == x){
                    cout << 1;
                }
                else{
                    cout << 0;
                }
            }
            cout << endl;
        }
    }
    return 0;
}