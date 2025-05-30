#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define N cout<<endl
#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull>
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vint a, b;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    for(int i=0; i<m; i++){
        int x; cin >> x;
        b.push_back(x);
    }
    vint ans;
    int i = 0, j = 0;
    while(i<n && j<m){
        if(a[i] > b[j]){
            ans.push_back(b[j++]);
        }
        else{
            ans.push_back(a[i++]);
        }
    }
    while(i<n){
        ans.push_back(a[i++]);
    }
    while(j<m){
        ans.push_back(b[j++]);
    }
    for(auto &i:ans){ cout << i << " ";}
    return 0;
}