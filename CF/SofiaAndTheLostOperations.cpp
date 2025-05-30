#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define N cout<<endl
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n], b[n];
        for(int i=0; i<n; i++){ cin >> a[i]; }
        for(int i=0; i<n; i++){ cin >> b[i]; }
        int m; cin >> m;
        multiset <int> d; int x;
        for(int i=0; i<m; i++){ cin >> x; d.insert(x); }
        int check = 1;
        for(int i=0; i<n; i++){
            if(d.find(b[i]) != d.end() && a[i] != b[i]){
                cout << "NO" << endl;
                int check = 0;
                break;
            }
        }
        if(check == 1){ cout << "YES" << endl; }
    }
    return 0;
}