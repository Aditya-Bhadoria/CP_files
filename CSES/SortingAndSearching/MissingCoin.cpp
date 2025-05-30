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
    int n; cin >> n;
    vll p(n); 
    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    ll sum = 0;
    for(int i=0; i<n; i++){
        if(p[i] > sum + 1){
            cout << sum+1 << endl; return 0; }
        else
            sum += p[i];
    }
    cout << sum + 1 << endl;
    return 0;
}