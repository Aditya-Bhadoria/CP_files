#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define N cout<<endl
#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull>
int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n;
        cin>>n;
        vll v(n);
        ll tsum=0;
        for(int i=0 ; i<n ; i++){
            cin>>v[i];
            tsum+=v[i];
            // s.insert({v[i],i});
        }
    
        ll mini=1e19,mx=0;
        ll sum=0;
        for(int i=0; i<n; i++){
            sum+=v[i];
            mini=min(mini,sum/(i+1));
            mx=max(mx,((tsum+(n-i-1))/(n-i)));
            tsum-=v[i];
        }
    
        cout<<mx-mini<<endl;
    }
    return 0;
}