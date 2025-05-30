#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0 ; i<n ; i++){ cin>>v[i]; }
    int lo=0;
    ll cnt=0;
    map<int,int>mp;
    for(int i=0 ;i<n ; i++){
        if((mp.size()<k)){
            mp[v[i]]++;
            cnt+=(i-lo+1);
        }
        else if((mp.size()==k)&&(mp.find(v[i])!=mp.end())){
            mp[v[i]]++;
            cnt+=(i-lo+1);
        }
        else{
            mp[v[lo]]--;
            if(mp[v[lo]]==0) mp.erase(v[lo]);
            lo++;
            i--;
        }
    }
    cout<<cnt<<endl;
    return 0;
}