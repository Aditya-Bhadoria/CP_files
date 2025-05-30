#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin>>n;
    vector<ll> sum(n+1);
    sum[0]=0;
    for(int i=0 ; i<n ; i++){
        ll a;
        cin>>a;
        sum[i+1]=sum[i]+a;
        sum[i]=(sum[i]%n+n)%n;
    }
    sum[n]=(sum[n]%n+n)%n;
    multiset<ll>s;
    map<ll,ll>mp;
    ll cnt=0;
    for(int i=0 ; i<=n ; i++){
        ll target=sum[i];
        if(s.find(target)!=s.end()){
            cnt+=mp[target];
        }
        mp[sum[i]]++;
        s.insert(sum[i]);
    }
    cout<<cnt<<endl;
    return 0;
}