#include <bits/stdc++.h>
using namespace std;
using ll=long long;
bool ispos(vector<pair<double,double>>v,int n, double time){
    double l=v[0].first-v[0].second*time;
    double r=v[0].first+v[0].second*time;
    for(int i=0 ; i<n ; i++){
        double ll=v[i].first-v[i].second*time;
        double rr=v[i].first+v[i].second*time;
        if(ll>r) return false;
        if(rr<l) return false;
        r=min(r,rr);
        l=max(l,ll);
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    vector<pair<double,double> > v;
    for(int i=0 ; i<n ; i++){
        double a,vi;
        cin>>a>>vi;
        v.push_back(make_pair(a,vi));
    }
    sort(v.begin(),v.end());
    double lo=0,hi=1e9;

    while(hi-lo>1e-6){
        double mid=lo+(hi-lo)/2;
        if(ispos(v,n,mid)){
            hi=mid;
        }
        else lo=mid+1e-6;
    }

    if(ispos(v,n,lo)) cout<<fixed<<setprecision(6)<<lo;
    else cout<<fixed<<setprecision(6)<<hi;
    return 0;

}