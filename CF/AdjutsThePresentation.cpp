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
        int n,m,q;
        cin>>n>>m>>q;
        deque<int>v(n);
        vector<int>o(n+1, 0);
        for(int i=0 ; i<n ; i++){
            cin>>v[i];
        }
        vector<int> b;
        for(int i=0; i<m; i++){
            cin >> b[i];
        }
        int check=1;
        int x =0, y=0;
        
        if(check){ cout<<"YA"<<endl; }
        else{ cout<<"TIDAK"<<endl; }
    }
    return 0;
}