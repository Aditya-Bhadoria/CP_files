#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int a,b; cin >> a >> b;
        if((a+b)%3 == 0 && max(a,b) <= 2*min(a,b)){ cout << "YES" << endl;}
        else{ cout << "NO" << endl; }
    }
    return 0;
}