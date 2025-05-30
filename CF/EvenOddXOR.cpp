#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define N cout<<endl
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll odd = (n+1)/2;
        ll even = n/2;
        ll rem1 = odd%4;
        ll rem2 = even%4;
        vector<ll> v(n,0);
        ll count = 20;
        for(int i=0; i<n; i+=2){
            v[i] = count++;
        }
        for(int i=1; i<n; i+=2){
            v[i] = count++;
        }
        if(rem1 == 1 && rem2 == 0){
            v[n-1] = 0;
        }
        else if(rem2 == 1 && rem1 == 1){
            v[n-1]=1; v[n-3]=2; v[n-5]=3; v[n-7]=7; v[n-9]=8;
            v[n-2]=16; v[n-4]=17; v[n-6]=19; v[n-8]=18; v[n-10]=15;
        }
        else if(rem1 == 2 && rem2 == 1){
            v[n-1] = 1; v[n-3] = 2;
            v[n-2] = 3;
        }
        else if(rem1 == 2 && rem2 == 2){
            v[n-1] = 1; v[n-3] = 4;
            v[n-2] = 0; v[n-4] = 5;
        }
        else if(rem1 == 3 && rem2 == 2){
            v[n-1] = 1; v[n-3] = 2; v[n-5] = 4;
            v[n-2] = 0; v[n-4] = 7;
        }
        else if(rem1 == 3 && rem2 == 3){
            v[n-1] = 1; v[n-3] = 2; v[n-5] = 3;
            v[n-2] = 8; v[n-4] = 7; v[n-6] = 15;
        }
        else if(rem1 == 0 && rem2 == 3){
            v[n-2] = 1; v[n-4] = 2; v[n-6] = 3;
        }
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        } N;
    }
    return 0;
}