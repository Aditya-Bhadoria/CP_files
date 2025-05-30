#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n], b[n];
        long ans = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        for(int i=0;i<n-1;i++){
            if(a[i]>b[i+1]){
                ans += a[i] - b[i+1];
            }
        }
        ans += a[n-1];
        cout << ans << endl;
    }
    return 0;
}