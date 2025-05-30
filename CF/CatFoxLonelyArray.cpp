#include <bits/stdc++.h>
using namespace std;
using ll=long long;
bool ispossible(vector<ll> v,int mid,int n){
    vector<ll> copy(v);
    int lo=0,hi=mid-1;
    if(v[hi]==0) return false;
    while(hi<n-1){
        hi++;
        v[hi]-=copy[lo];
        lo++;
        if(v[hi]==0) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> num(n);
        for(int i=0 ; i<n; i++){
            cin>>num[i];
        }
        vector<int> nums(num);
        int arr[20][n];
        int j=0;
        while(j<20){
            for(int i=0 ; i<n ; i++){
                arr[j][i]=(num[i]&1);
                num[i]>>=1;
            }
            j++;
        }
        int ans=INT_MIN;
            for(int i=0 ; i<20 ; i++){
                int check1=0;
                int check2=0;
                vector<ll>sum(n,0);
                sum[0]=arr[i][0];
                if(arr[i][0]==0) check1=1;
                else check2=1;
                for(int j=1 ; j<n ; j++){
                    sum[j]+=(sum[j-1]+arr[i][j]);
                    if(arr[i][j]==0) check1=1;
                    if(arr[i][j]==1) check2=1;
                }
            if(check1==0||check2==0) ans=max(ans,1);
            else{
                int lo=1,hi=n;
                while(hi-lo>1){
                    int mid=lo+(hi-lo)/2;
                    if(ispossible(sum,mid,n)){
                        hi=mid;
                    }
                    else{
                        lo=mid+1;
                    }
                }
                if(ispossible(sum,lo,n)) ans=max(ans,lo);
                else ans=max(ans,hi);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}