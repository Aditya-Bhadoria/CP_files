#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define N cout<<endl
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string q;
        cin >> q;
        int ch[7] = {0};
        int ans = 0;
        for(int i=0; i<n; i++){
            ch[q[i]-'A']++;
        }
        for(int i=0; i<7; i++){
            if(ch[i] < m){
                ans += m - ch[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}