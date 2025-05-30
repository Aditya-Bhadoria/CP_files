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
    ll median = p[n/2], ans = 0;
    for(int i=0; i<n; i++){
        ans += abs(median - p[i]);
    }
    cout << ans << endl;
    return 0;
}