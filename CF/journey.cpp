#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n,a,b,c;
        cin >> n >> a >> b >> c;
        int ans;
        int compare = a + b + c;
            ans = n/compare;
            ans *= 3;
            n = n%compare;
            if(n<=a && n){
                ans += 1;
            }
            else if(n <= a+b && n){
                ans += 2;
            }
            else if(n){
                ans += 3;
            }
            cout << ans << endl;
    }
    return 0;
}