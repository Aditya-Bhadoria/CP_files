#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define N cout<<endl
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        ll x; cin >> x;
        ll ans = 1;
        while(x>3){
            x = x/4;
            ans *= 2;
        }
        cout << ans << endl;
    }
    return 0;
}