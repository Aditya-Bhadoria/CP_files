#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,t; cin>>n>>t;
    vector<int> v(n);
    map<int,vector<int> >mp;
    for(int i=0 ; i<n ;i++){
        cin>>v[i];
        mp[v[i]].push_back(i);
    }
    for(int i=0 ; i<n-1; i++){
        for(int j=i+1; j<n ; j++){
            int tar=t-v[i]-v[j];
            if(mp.find(tar)!=mp.end()){
                if((mp[tar].back()!=i)&&(mp[tar].back()!=j)){
                    cout<<i+1<<" "<<j+1<<" "<<mp[tar].back()+1;
                    return 0;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}