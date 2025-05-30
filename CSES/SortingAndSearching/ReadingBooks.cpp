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
    ll sum = 0, maxE = INT_MIN;
    vll t(n); for(int i=0; i<n; i++){ cin >> t[i]; sum += t[i]; maxE = max(maxE, t[i]); }
    cout << max(2*maxE, sum);
    return 0;
}