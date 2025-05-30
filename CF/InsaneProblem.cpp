#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define N cout<<endl
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        if(l1>r2){
            cout << 0 << endl;
            continue;
        }
        double ok = log(r2/l1);
        ok /= log(k);
        ll high = (ll)ok;
        ok = log(l2/r1);
        ok /= log(k);
        ll low = ok;
        if(low < 0){ low  = 0;}
        for(ll i = low; i<= high; i++){

        }
    }
    return 0;
}