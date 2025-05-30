#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>v(n);
        for(int i=0 ; i<n ; i++){
            cin>>v[i];
        }
        if(n&1){
            ll ans=LLONG_MAX;
            for(int i=0 ; i<n ; i++){
                ll diff=1;
                for(int j=0 ; j<n ; j+=2){
                    ll num1,num2;
                    int check=0;
                    if(j!=i) num1=v[j];
                    else{
                        j++;
                        if(j<n-1)num1=v[j];
                        else check=1;
                    }
                    if(j+1!=i&&(j+1<n)) num2=v[j+1];
                    else{
                        j++;
                        if(j+1<n)num2=v[j+1];
                        else check=1;
                    }
                    if(check) break;
                    diff=max(diff,abs(num2-num1));

                }
                ans=min(ans,diff);
            }
            cout<<ans<<endl;
        }
        else{
            ll diff=0;
            for(int i=1 ; i<n ; i+=2){
                diff=max(diff,v[i]-v[i-1]);
            }
            cout<<diff<<endl;
        }
    }
    return 0;
}