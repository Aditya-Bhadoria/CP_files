#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define N cout<<endl
#define vint vector<int>
#define vll vector<ll>
const ll mod = 1e9 + 7;
ll factorial(ll x){
    if(x == 1 || x == 0){
        return 1;
    }
    ll ans = 1;
    for(int i=2; i<=x; i++){
        ans = (ans%mod)*(i%mod);
        ans %= mod;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n, minEle = 0; cin >> n;
        vll v(n); for(int i=0; i<n; i++){ cin >> v[i]; }
        sort(v.begin(),v.end());
        vector<vector<int> > vv(n);
        for(int i=0 ; i<n ;i++){
            if(v[i]==v[0]) minEle++;
            int x=v[i];
            while(x){
                vv[i].push_back(x&1);
                x>>=1;
            }
        }
        if(minEle==1){
            cout<<"0"<<endl;
            continue;
        }
        int flag=1;
        for(int j=0 ; j<vv[0].size();j++){
            if(vv[0][j]){
                for(int i=0 ; i<n ; i++){
                    if(vv[i][j]!=vv[0][j]){
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==0) break;
        }
        if(flag == 0){ cout << "0" << endl; }
        else{
            ll ans = (minEle%mod)*((minEle-1)%mod);
            ans = (ans%mod)*(factorial(n-2)%mod);
            ans %= mod;
            cout << ans << endl;
        }
    }
    return 0;
}