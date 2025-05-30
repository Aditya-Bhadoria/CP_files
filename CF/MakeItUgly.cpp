#include <iostream>
#include <vector>
#include <algorithm>
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
        vector<int> v(n);
        for(int i=0 ; i<n ; i++){
            cin>>v[i];
        }
        int a=0;
        int b=0,c=INT_MAX;
        for(int i=0 ; i<n ; i++){
            if(v[i]!=v[0]){
                a=i;
                break;
            }
        }
        for(int i=n-1; i>=0 ; i--){
            if(v[i]!=v[n-1]){
                b=n-1-i;
                break;
            }
        }
        int prev=a,nex=0;
        for(int i=a+1 ; i<n ; i++){
            if(nex==0){
                if(v[i]!=v[0]){
                    nex=i;
                    c=min(nex-prev-1,c);
                }
            }
            else{
                if(v[i]!=v[0]){
                    prev=nex;
                    nex=i;
                    c=min(nex-prev-1,c);
                }
            }
        }
        int d=min(a,b);
        int ans=min(c,d);
        if(ans) cout<<ans<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}